// Print nodes in a linked list with a while loop

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    // Creating a 'blank' list
    node *list = NULL;

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        // Create a memory for 'n' with the size of a node
        node *n = malloc(sizeof(node));
        // Failsafe
        if (n == NULL)
        {
            return 1;
        }
        // (*n).number = get_int("Number: ");
        n->number = get_int("Number: ");

        // (*n).next = list;
        // Saving the address of previous 'n' to the 'next' memory, for the first loop, it will be null as there are no address saved previously
        n->next = list;

        // Copy the address of the current 'n' to list
        list = n;
    }

    // Copying the address in 'list' for ptr
    node *ptr = list;
    while (ptr != NULL)
    {
        // Printing of the number in the address
        printf("%i\n", ptr->number);
        // Copying address in 'next' memory to access the previous memory
        ptr = ptr->next;
    }
    return 0;
}
