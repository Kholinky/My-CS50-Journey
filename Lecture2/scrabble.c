#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Assign points to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate(string word);

int main(void)
{
    //Prompt user to enter words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Calculate the points
    int score1 = calculate(word1);
    int score2 = calculate(word2);
    //Print the result
    if (score1 > score2)
    {
        printf ("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf ("Player 2 wins!\n");
    }
    else
    {
        printf("Its a tie!\n");
    }
}


//Function to calculate the points
int calculate(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
