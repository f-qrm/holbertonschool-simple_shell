# 🐚 Simple Shell Project

<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

## 📌 Description

This project is a **simple UNIX command-line interpreter**, or shell, written in C.  
It replicates fundamental features of the Unix shell to better understand how a shell works behind the scenes.

This shell project was created as part of the **Low-Level Programming** curriculum at Holberton School, with a focus on:

- Process creation and management (`fork`, `execve`, `wait`)
- Environment variables and `PATH`
- File descriptors and input/output (`getline`, `write`)
- String parsing using `strtok`
- Handling interactive and non-interactive modes

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Ubuntu 20.04 LTS
- GCC compiler with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Code must follow **Betty style** (checked with `betty-style.pl` and `betty-doc.pl`)
- No global variables
- Max 5 functions per file
- All header files should be include guarded
- Use **only** allowed system functions

### GitHub

There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

---

## 🔧 Authorized Functions

access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free,
getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror,
printf, fprintf, vfprintf, sprintf, putchar, read, readdir, signal, stat,
lstat, fstat, strtok, wait, waitpid, wait3, wait4, write

---

## 🗃️ File Structure

.
├── main.c             # Entry point, handles the shell loop
├── prompt.c           # Prompt logic (display and read input)
├── parser.c           # Parses the input command line
├── executor.c         # Executes commands using fork + execve
├── path.c             # Searches command in PATH
├── env.c              # Handles environment (get, print, set)
├── shell.h            # Function prototypes and shared headers
├── man_1_hsh.1        # Manual page for the shell
├── .gitignore
└── README.md


---

## ⚙️ Compilation

You can compile the shell with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

---

## ▶️ Usage

### 🔹 Interactive Mode

```bash
$ ./hsh
($) ls -l
total 16
-rw-r--r-- 1 user user 1234 main.c
($) exit
$

