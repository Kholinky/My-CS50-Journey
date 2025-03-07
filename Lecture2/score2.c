#include <stdio.h>
#include <cs50.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("score: ");
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}

// Calculating average
float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
