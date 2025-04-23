#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"


/**
 * get_path - retrieves a malloc'd copy of the PATH from environ
 * Return: pointer to the value (must be free'd), or NULL if not found
 */
char *get_path(void)
{
	int i = 0;
	char *path;
	char *copy;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			copy = malloc(strlen(path) + 1);
			if (!copy)
				return (NULL);
			strcpy(copy, path);
			return (copy);
		}
		i++;
	}
	return (NULL);
}

/**
 * _which - searches for each program in the PATH and prints its location
 * @ac: argument count
 * @av: argument vector (program name and targets to search)
 *
 * Return: 0 on success, or 1 on error
 */
int _which(int ac, char **av)
{
	struct stat st;
	char full_path[1024];
	char *token, *path_copy;
	int i, found;
	char *path = get_path();

	if (!path)
	{
		return (0); }
	for (i = 1; i < ac; i++)
	{
		found = 0;
		path_copy = malloc(strlen(path) + 1);
		if (!path_copy)
		{
			free(path);
			return (1); }
		strcpy(path_copy, path);
		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			printf("Testing: %s/%s\n", token, av[i]);
			snprintf(full_path, sizeof(full_path), "%s/%s", token, av[i]);
			if (stat(full_path, &st) == 0)
			{
				printf("%s: %s\n", av[i], full_path);
				found = 1;
				break; }
			token = strtok(NULL, ":"); }
		if (!found)
			printf("%s: NOT FOUND\n", av[i]);
		free(path_copy);
	}
	free(path);
	return (0);
}
