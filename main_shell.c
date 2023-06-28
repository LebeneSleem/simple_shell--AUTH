#include "shell.h"

/**
 * main - Shell entry Point
 * @ac: Argument count
 * @av: Argument vector
 * @env: environment variable
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		handle_command_prompt(av, env);
	return (0);
}
