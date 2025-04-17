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
	char *cmd = strtok(line, " ");
	char **argv;

	if (cmd == NULL)
		return (NULL);

	argv = malloc(2 * sizeof(char *));
	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	argv[0] = cmd;
	argv[1] = NULL;

	return (argv);
}

/**
 * execute_command - forks a child process and executes a command
 * @args: NULL-terminated array of arguments
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("waitpid");
	}
}
