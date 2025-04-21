#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <signal.h>
/**
 * main - entry point for the simple_shell program
 *
 * Return: EXIT_SUCCESS on success
 */
int main(void)
{
	char *line;
	char **args;
	int interactive = is_interactive();
	int ac;

	while (1)
	{
		if (interactive)
			display_prompt();

		line = read_line();
		if (line == NULL)
		{
			if (interactive)
				putchar('\n');
			break;
		}
		args = parse_line(line);
		if (args && args[0])
		{
			if (strcmp(args[0], "exit") == 0)
				handle_exit(args, line);

			else if (strcmp(args[0], "which") == 0)
			{
				ac = 0;
				while (args[ac])
					ac++;
				if (ac > 1)
					_which(ac, args);
				else
					printf("Usage: which <command1> <command2> ...\n");
			}
			else if (strcmp(args[0], "env") == 0)
			{
				handle_env(args);
			}
			else
				execute_command(args);
		}
		free(args);
		free(line);
	}
	return (EXIT_SUCCESS);
}
