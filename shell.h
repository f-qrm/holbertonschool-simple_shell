#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>

extern char **environ;

/* Function prototypes */
int is_interactive(void);
void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
int _which(int ac, char **av);
char *get_path(void);
char *search_path(char *cmd);
void handle_exit(char **args, char *line, int last_status);
void handle_env(char **args);

#endif /* SHELL_H */