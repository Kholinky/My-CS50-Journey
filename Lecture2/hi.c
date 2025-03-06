#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Using Array to assign words
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";
    
    // Different type of syntax to print characters/words
    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%s\n", words[1]);
}
