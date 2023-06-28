#include "shell.h"

/**
 * free_memory - frees memory allocated
 * @inputptr: Pointer to memory allocated
 */

void free_memory(char **inputptr)
{
	if (*inputptr != NULL)
	{
		free(*inputptr);
		*inputptr = NULL;
	}
}

/**
 * handle_command_prompt - prints command prompt,
 * gets input
 * @av: argument vector
 * @env: environment variable
 * Return: 0 (Success)
 */
void handle_command_prompt(char **av, char **env)
{
	char *inputptr = NULL;
	size_t n = 0;
	ssize_t input;
	int a;
	char *argv[] = {NULL, NULL};

	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "simple_shell$  ", 15);
		}
		input = getline(&inputptr, &n, stdin);
		if (input == -1)
		{
			free(inputptr);
			exit(EXIT_FAILURE);
		}
		a = 0;
		while (inputptr[a])
		{
			if (inputptr[a] == '\n')
				inputptr[a] = 0;
			a++;
		}
		argv[0] = inputptr;
		handle_command_execution(argv, env);
		free_memory(&inputptr);
		inputptr = NULL;
	}
	free(inputptr);
}
