#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    //Counting the number of letter
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if the selected letter is in the range of lowercase lib
        // You can use 'toupper(s[i])' instead of all the calculations below
        // Remember to #include <ctype.h> for above syntax
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // Change all lowercase to uppercase
            printf("%c", s[i] - ('a' - 'A'));
        }
        else
        {
            // No change and just print
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
