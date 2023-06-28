#include "shell.h"

/**
 * handle_command_execution - executes a command using child
 * process
 * @argv: Array of argument
 * @env: Environment variable
 */

void handle_command_execution(char **argv, char **env)
{
	int status;
	pid_t child = fork();

	if (child == -1)

	{
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

