#include "shell.h"
/**
 * execute_command - Execute a command in a new process.
 * @command: The command to execute.
 * Return: void.
 */
void execute_command(char *command)
{
	if (_strcmp(command, "exit") == 0)
	{	free(command);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(command, "env") == 0)
	{	char **env_var = environ;
		while (*env_var != NULL)
		{	myprint(*env_var);
			myprint("\n");
			env_var++;
		}
		return;
	}
	else
	{	pid_t pid = fork();
		if (pid < 0)
		{	perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{	char **args = tokenize(command);
			if (args[0] == NULL)
			{	free_tokens(args);
				exit(EXIT_FAILURE);
			}
			execve(args[0], args, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
}
