#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int diff;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // for all candidates (# candidates = # rank)
    for (int i = 0; i < candidate_count; i++)
    {
        //if given name in array of candidate names
        if (strcmp(candidates[i], name) == 0)
        {
            //update ranks[rank] with i, indicator of candidate per candidate_count
            ranks[rank] = i;

            //return true (vote counted)
            return true;
        }
    }
    //return false (vote not counted)
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //for each candidate, i
    for (int i = 0; i < candidate_count; i++)
    {
        //for each candidate, j
        for (int j = i + 1; j < candidate_count; j++)
        {
            //if i < j (i.e. higher rank)
            if (i < j)
            {
                //increase number of voters who prefer i over j
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //for all candidates (i)
    for (int i = 0; i < candidate_count; i++)
    {
        //for all candidates (j, to compare to i)
        for (int j = i + 1; j < candidate_count; j++)
        {
            //initialize variables
            int winner;
            int loser;
            bool same = true;

            //if preference for i over j is greater than preference for j over i
            if (preferences[i][j] > preferences[j][i])
            {
                //assign winner (i), loser (j)
                winner = i;
                loser = j;
                same = false;
            }
            //if preference for j over i is greater than preference for i over j
            else if (preferences[i][j] < preferences[j][i])
            {
                //assign winner (j), loser (i)
                winner = j;
                loser = i;
                same = false;
            }

            //if winner and loser assigned, update pair in pairs with winner and loser
            if (same == false)
            {
                pairs[pair_count].winner = winner;
                pairs[pair_count].loser = loser;
                //add to pair_count (init at 0)
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    //for each pair
    for (int i = 0; i < pair_count; i++)
    {
        //calculate difference (strength of victory)
        pairs[i].diff = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }
    //for each pair at given index
    for (int i = 0; i < pair_count; i++)
    {
        //for each pair at next index
        for (int j = i + 1; j < pair_count; j++)

            {
                //sort in descending order using selection sort
                if (pairs[i].diff < pairs[j].diff)
                {
                    pair sort = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = sort;
                }
            }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        //if any winner is not also a loser, no cycle
        if (cycle(pairs[i].winner, pairs[i].loser) == false)
        {
            //lock pairs
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

//check for cycle
bool cycle(int winner, int loser)
{

    if (winner == loser)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][winner])
        {
            if (cycle(i,winner))
            {
                return true;
            }
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    //for each candidate, i
    for (int i = 0; i < candidate_count; i++)
    {
        bool winner = true;

        //for each candidate, j (compared to i)
        for (int j = 0; j < candidate_count; j++)
        {
            //if i in locked pairs (where i is the loser)
            if (locked[i][j])
            {
                winner = false;
                break;
            }
        }
        if (winner)
        {
            //print i (winner)
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}