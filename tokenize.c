#include "shell.h"
/**
 * tokenize - Tokenize a command string into
 * an array of tokens
 * @command: The command string to tokenize.
 *
 * Return: An array of strings (tokens).
 */
char **tokenize(char *command)
{
	char **tokens = malloc(sizeof(char *) * TOKEN_BUFFER_SIZE);
	char *token;
	int index = 0;

	if (!tokens)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, " \t\n");
	while (token != NULL)
	{
		tokens[index] = _strdup(token);
		if (!tokens[index])
		{
			perror("strdup failed");
			exit(EXIT_FAILURE);
		}
		index++;

		if (index >= TOKEN_BUFFER_SIZE)
		{
			perror("Too many tokens");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[index] = NULL;

	return (tokens);
}
