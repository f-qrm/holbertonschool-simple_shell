#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>

extern char **environ;

/* Function prototypes */
int is_interactive(void);
void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
void execute_command(char **args);
int _which(int ac, char **av);
char *get_path(void);
void handle_exit(char **args, char *line);

#endif /* SHELL_H */
