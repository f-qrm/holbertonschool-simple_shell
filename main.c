#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
/**
 *
 *
 *
 */
int main(void)
{
	pid_t pid;
	int status, i;
	ssize_t nread;
	size_t len = 0;
	char *token;
	char *line = NULL;
	char *argv[2];

	while (1)
	{

		printf("┌∩┐(◣_◢)┌∩┐ ");
		fflush(stdout);

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			break;
		}
		if (line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
		}
		token = strtok(line, " ");
		if (line[0] == '\0')
		{
			continue;
		}
		pid = fork();

		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0)
		{
			i = 0;
			while (token != NULL && i < 63)
			{
				argv[i++] = token;
				token = strtok(NULL, " ");
			}
			argv[i] = NULL;

			execve(argv[0], argv, environ);
			perror("Error");
			return (1);
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
