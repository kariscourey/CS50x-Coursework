#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    //initialize player #
    string player1 = "Player 1";
    string player2 = "Player 2";
    string winner;

    // get input words from both players
    string word1 = get_string("%s: ", player1);
    string word2 = get_string("%s: ", player2);

    // score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // print winner
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        if (score1 > score2)
        {
            winner = player1;
        }
        else
        {
            winner = player2;
        }
        printf("%s wins!\n", winner);
    }
}

int compute_score(string word)
{
    // compute and return score for string

    int score = 0;
    int index;
    int low;
    int high;
    bool letter = false;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //check if letter
        if (isupper(word[i]))
        {
            low = 65;
            high = 90;
            letter = true;
        }

        else if (islower(word[i]))
        {
            low = 97;
            high = 122;
            letter = true;
        }

        else
        {
            continue;
        }

        //if letter, add to score
        if (letter == true)
        {
            index = word[i] - low;
            score = score + POINTS[index];
        }
    }
    return score;
}
