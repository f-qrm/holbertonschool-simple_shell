#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"
/**
 * search_path_and_exec - search in PATH and execute command if found
 * @args: command and arguments
 */
void search_path_and_exec(char **args)
{
	char *path = get_path(), *copy, *token;
	char full_path[1024];

	if (!path)
	{
		fprintf(stderr, "%s: Command not found\n", args[0]);
		_exit(EXIT_FAILURE);
	}

	copy = malloc(strlen(path) + 1);
	if (!copy)
	{
		free(path);
		perror("malloc");
		_exit(EXIT_FAILURE);
	}
	strcpy(copy, path);
	free(path);

	token = strtok(copy, ":");
	while (token)
	{
		sprintf(full_path, "%s/%s", token, args[0]);
		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, args, environ);
			perror("execve");
			free(copy);
			_exit(EXIT_FAILURE);
		}
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: Command not found\n", args[0]);
	free(copy);
	_exit(EXIT_FAILURE);
}

/**
 * execute_command - executes a command by forking and using execve
 * @args: command arguments
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
		search_path_and_exec(args);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("waitpid");
	}
}
