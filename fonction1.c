#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * is_interactive - checks if shell is running in interactive mode
 * Return: 1 if standard input is a terminal, 0 otherwise
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * display_prompt - prints the shell prompt to stdout
 */
void display_prompt(void)
{
	printf("💻 \033[1;96m➜ \033[0m ");
	fflush(stdout);
}

/**
 * read_line - reads a line of input from stdin
 * Return: pointer to the read line, NULL on EOF or error
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);

		return (NULL);
	}
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

/**
 * parse_line - splits a line into a command for execution
 * @line: input line to parse
 * Return: NULL-terminated array of arguments, or NULL on empty line
 */
char **parse_line(char *line)
{
	int bufsize = 64, pos = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t");
	while (token && pos < bufsize - 1)
	{
		tokens[pos++] = token;
		token = strtok(NULL, " \t");
	}
	tokens[pos] = NULL;
	return (tokens);
}
