#include <stdio.h>
#include <cs50.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);

}




// Calculater to find the number of letters using array
// This function is the same as 'strlen()', remember to include string.h!
int string_length(string name)
{
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    return n;
}
