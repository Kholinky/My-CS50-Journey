#include <stdio.h>
#include <cs50.h>

void print_row(int n);

// Defining column of n
int main(void)
{
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
}






// Defining Row of n
void print_row(int n)
{
    for (int i = 0; i < n; i ++)
    {
        printf("#");
    }
    printf("\n");
}
