#include "shell.h"
/**
 * shell_loop - function is responsible for the main loop of the shell,
 * where it repeatedly prompts for user input,
 * reads the command and execute it
 *
 * Return: void.
 */
void shell_loop(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t input_length;

	while (1)
	{
		if (isatty(STDIN_FILENO))  /* Check if input is from a terminal*/
		{
			display_prompt();
		}
		input_length = getline(&command, &command_size, stdin);
		if (input_length == -1)
		{
			if (isatty(STDIN_FILENO)) /* Handle end of file (Ctrl+D) or error */
			{
				myprint("\n");
			}
			break;
		}
		/* Remove trailing newline character */
		if (command[input_length - 1] == '\n')
		{
			command[input_length - 1] = '\0';
		}
		if (_strspn(command, " \t\n\r\a") < _strlen(command))
		{
		execute_command(command);
	}
	}
	free(command);
}
