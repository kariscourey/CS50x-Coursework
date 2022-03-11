#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    //initialize Player #
    string player1 = "Player 1";
    string player2 = "Player 2";
    string winner;

    // Get input words from both players
    string word1 = get_string("%s: ", player1);
    string word2 = get_string("%s: ", player2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 = score2)
    {
        printf("Tie!");
    }
    else
    {
        if (score 1 > score 2)
        {
            winner = player1;
        }
        else
        {
            winner = player2;
        }
        printf("%s wins!", player2);
    }
}

int compute_score(string word)
{
    // Compute and return score for string

    int score = 0;
    int index;
    int low;
    int high;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            low = 65;
            high = 90;
        }

        else if (islower(word[i]))
        {
            low = 97;
            high = 122;
        }

        else
        {
            continue;
        }

        index = word[i] - low;
        score = score + POINTS[index];


    }
}
