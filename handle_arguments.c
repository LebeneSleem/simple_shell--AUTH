#include "shell.h"

/**
 * handle_arguments - function that handles command
 * line arguments in a simple unix shell
 * by tokenizing the command line input
 * and handles the built in exit function
 * if the token suppliedis exit
 * @lineptr: command line input to tokenize
 * @argv: Array to store the tokens
 */

void handle_arguments(char *lineptr, char **argv)
{
	int b = 0;
	char *args, *lineptr_copy;

	lineptr_copy = _strdup(lineptr);
	if (lineptr_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	args = strtok(lineptr_copy, " ");
	while (args != NULL)
	{
		argv[b] = strdup(args);
		if (argv[b] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		b++;
		args = strtok(NULL, " ");
	}
	argv[b] = NULL; /* End of the array */

	free(lineptr_copy);
}
