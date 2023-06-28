#include "shell.h"

/**
 * handle_command_execution - handles the execution of commands
 * inputed
 * @argv: Array of strings of the command
 * @env: Environment variables of the command
 */

void handle_command_execution(char **argv, char **env)
{
	pid_t child;
	int status;
	char *path;

	child = fork();/*fork a child process*/

	if (child == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		path = handle_path(argv[0]);/*get the path of the command*/
		if (path != NULL)
		{
			if (execve(path, argv, env) == -1)
			{
				perror("execve");
				free(path);
				exit(EXIT_FAILURE);
			}
			free(path);
		}
	}
	wait(&status);/*parent process shd wait for the child*/
}
