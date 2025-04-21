#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"
#include <signal.h>
/**
 * search_path_and_exec - Searches for a command in the PATH
 * and returns the full path if found
 * @cmd: Command name (e.g., "ls")
 *
 * Return: A malloc'd string containing the full path to the command
 * if found, or NULL if not found or on error.
 */
char *search_path(char *cmd)
{
	char *path = get_path(), *copy, *token;
	char full_path[1024];
	char *result = NULL;

	if (!path)
	{
		return (NULL);
	}

	copy = malloc(strlen(path) + 1);
	if (!copy)
	{
		free(path);
		return (NULL);
	}
	strcpy(copy, path);
	free(path);

	token = strtok(copy, ":");
	while (token)
	{
		sprintf(full_path, "%s/%s", token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			result = malloc(strlen(full_path) + 1);
			if (result != NULL)
				strcpy(result, full_path);
			break;
		}
		token = strtok(NULL, ":");
	}
	free(copy);
	return (result);
}
/**
 * execute_command - Executes a command by forking and calling execve
 * if the command exists either directly or through PATH resolution
 * @args: Array of command arguments (e.g., {"ls", "-l", NULL})
 *
 * Return: Nothing. Handles process creation and error messages.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;

	if (strchr(args[0], '/'))
	{
		if (access(args[0], X_OK) == 0)
		{
			cmd_path = malloc(strlen(args[0]) + 1);
			if (cmd_path)
				strcpy(cmd_path, args[0]);
		}
	}
	else
	{
		cmd_path = search_path(args[0]); }
	if (!cmd_path)
	{
		fprintf(stderr, "%s: Command not found\n", args[0]);
		return; }
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return; }
	if (pid == 0)
	{
		execve(cmd_path, args, environ);
		perror("execve");
		free(cmd_path);
		_exit(EXIT_FAILURE); }
	else
	{
		free(cmd_path);
		if (waitpid(pid, &status, 0) == -1)
			perror("waitpid"); }
}
/**
 * handle_exit - Handles the "exit" command in the shell
 * @args: Argument array (command and optional exit status)
 * @line: Input line read from the user (to be freed)
 */
void handle_exit(char **args, char *line)
{
	free(args);
	free(line);
	exit(0);
}
/**
 *
 *
 *
 */
void handle_env(char **args)
{
	int i = 0;

	if (args[1] != NULL)
		return;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
