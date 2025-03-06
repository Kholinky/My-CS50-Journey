#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 3;
    int score[n];
    for (int i = 0; i < n; i++)
    {
        score[i] = get_int("Score: ");
    }

    printf ("Average: %f\n", (score[0] + score[1] + score[2]) / (float) n );
}
