#include <stdio.h>
#include <cs50.h>

void print_row(int bricks, int spaces, int gap, int bricks2);

int main(void)
{
    // Prompt user to enter height
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);

    // Print the height
    for (int i = 0; i < x; i++)
    {
        print_row(i+1, x, i, i+1);
    }
}

void print_row(int bricks, int spaces, int gap, int bricks2)
{
    //print spaces
    for (int j = spaces; j > bricks; j--)
    {
        printf(" ");
    }
    //print left bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    //print gaps
        printf("  ");
    //print right bricks
    for (int p = 0; p < bricks2; p++)
    {
        printf("#");
    }
    printf("\n");
}
