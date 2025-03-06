#include <stdio.h>
#include <cs50.h>

void print_row(int bricks, int spaces);

int main(void)
{
    // Prompt user to enter height
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1);

    // Print the height
    for (int i = 0; i < x; i++)
    {
        print_row(i+1, x);
    }
}

void print_row(int bricks, int spaces)
{
    for (int j = spaces; j > bricks; j--)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
