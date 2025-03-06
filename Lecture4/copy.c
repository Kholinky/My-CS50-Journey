#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    // Allocating memory for 't'
    char *t = malloc(strlen(s) + 1);
    // Coding defensively if computer as no memory to allocate
    if (t == NULL)
    {
        return 1;
    }

    // you can use strcpy(t,s); for copying data
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // Coding defensively if computer as no memory to allocate
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // free memory that has been allocated
    free(t);
}
