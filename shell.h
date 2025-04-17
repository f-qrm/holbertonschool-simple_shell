#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>

/* Pour execve */
extern char **environ;

/* prototypes des fonctions de main.c */
void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
void execute_command(char **args);
int is_interactive(void);

#endif /* SHELL_H */
