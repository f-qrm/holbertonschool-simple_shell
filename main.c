#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - entry point for the simple_shell program
 *
 * Reads and executes commands until EOF or interruption.
 * Uses interactive mode detection to display prompt when appropriate.
 * Return: EXIT_SUCCESS on normal termination
 */
int main(void)
{
	char *line;
	char **args;
	int interactive = is_interactive();

	while (1)
	{
		if (interactive)
			display_prompt();

		line = read_line();
		if (!line)
		{
			if (interactive)
				putchar('\n');
			break;
		}
		if (line[0] != '\0')
		{
			args = parse_line(line);
			execute_command(args);
			free(args);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
