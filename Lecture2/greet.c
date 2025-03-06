#include <stdio.h>
#include <cs50.h>

// int argc = how many argument counts provide
// string argv = array of all the words typed in the command line
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }
}
