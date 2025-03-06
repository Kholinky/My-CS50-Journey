#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>




int main(int argc, string argv[])
{
    // Check if the command argument is not 2, example: ./caesar 1 2 (3 arguments)
    if (argc != 2)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    // Check if the 2nd argument is not a digit, example: ./caesar 10a ('a' is not a digit)
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf ("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Converting the inputed number (string) into an integer
    int k = atoi(argv[1]);


    // Prompt user to input a text to cipher
    string plaintext = get_string("Plaintext: ");

    // Output of ciphertext
    printf ("Ciphertext: ");


    // Using the 'k', calculate the new index of the letter
    for (int j = 0; j < strlen(plaintext); j++)
    {
        // if plaintext is uppercase
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }
        // if plaintext is lowercase
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }
        // if plaintext is not a letter
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
