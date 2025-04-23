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

