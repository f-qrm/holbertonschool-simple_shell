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
 * search_path - Searches for a command in the PATH
 * and returns the full path if found
 * @cmd: Command name (e.g., "ls")
 * Return: A malloc'd string containing the full path to the command
 * if found, or NULL if not found or on error.
 */
char *search_path(char *cmd)
{
	char *path = get_path(), *copy, *token;
	char full_path[1024];
	char *result = NULL;

	if (!path || *path == '\0')
	{
		free(path);
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
int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;

	if (strchr(args[0], '/'))
	{
		if (access(args[0], X_OK) == 0)
		{
			cmd_path = malloc(strlen(args[0]) + 1);
			if (cmd_path != NULL)
				strcpy(cmd_path, args[0]); }
	}
	else
		cmd_path = search_path(args[0]);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		exit(127); }
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (1); }
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
		{
			perror("waitpid");
			return (1); }
		return (WEXITSTATUS(status)); }
}

/**
 * handle_exit - Handles the "exit" command in the shell
 * @args: Argument array (command and optional exit status)
 * @line: Input line read from the user (to be freed)
 *  @last_status: The exit status of the last executed
 * command, used if no status is given.
 */
void handle_exit(char **args, char *line, int last_status)
{
	int exit_status = last_status;

	if (args[1] != NULL)
		exit_status = (atoi(args[1]));
	free(args);
	free(line);
	exit(exit_status);
}
/**
 * handle_env - Handles the "env" built-in command
 * @args: Argument array (should contain only "env")
 *
 * Description: Prints all environment variables if called without arguments.
 * If any argument is passed (e.g., "env something"),
 * the function does nothing.
 * Return: Nothing
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
