#include "shell.h"

/**
 * free_tokens - Free the memory allocated for the tokens array.
 * @tokens: The array of tokens to free.
 *
 * Return: void.
 */
void free_tokens(char **tokens)
{
    int i = 0;
    while (tokens[i] != NULL)
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}
