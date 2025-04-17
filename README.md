```markdown
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

## ✅ Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Ubuntu 20.04 LTS
- GCC compiler with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Code must follow **Betty style** (checked with `betty-style.pl` and `betty-doc.pl`)
- No global variables
- Max 5 functions per file
- All header files should be include guarded
- Use **only** allowed system functions

## 🔧 Authorized Functions

```c
access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free,
getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror,
printf, fprintf, vfprintf, sprintf, putchar, read, readdir, signal, stat,
lstat, fstat, strtok, wait, waitpid, wait3, wait4, write
```
## 🗃️ File Structure

```
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
```
## ⚙️ Compilation

You can compile the shell with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## ▶️ Usage

### 🔹 Interactive Mode

```bash
$ ./hsh
($) ls -l
total 16
-rw-r--r-- 1 user user 1234 main.c
($) exit
$
```

### 🔹 Non-Interactive Mode

```bash
$ echo "ls -l" | ./hsh
-rw-r--r-- 1 user user 1234 main.c
```
## 📚 Learning Objectives

By the end of this project, you should understand:

- Who created Unix, the shell, and the B language
- How a shell works under the hood
- The difference between a system call and a function
- How processes are created and terminated
- How PATH is used to locate executables
- How to use `execve`, `fork`, and `wait`
- How to detect end-of-file (EOF) and handle input modes

## 🧠 Features

| Feature           | Description                               |
|------------------|-------------------------------------------|
| Command execution| Runs commands found in PATH using `execve`|
| PATH handling     | Searches directories in `PATH`            |
| Environment       | Supports `env` built-in                   |
| Interactive mode  | Displays prompt and waits for input       |
| Non-interactive   | Accepts piped input or from file          |
| Built-ins         | Handles simple built-ins like `exit`, `env`|

## 🛠️ Example Built-ins

```bash
($) env
HOME=/home/user
PATH=/usr/bin:/bin:/usr/local/bin
($) exit
```

## 📖 Manual Page

You can open the custom manual page with:

```bash
man ./man_1_hsh.1
```

## 🧪 Testing

You can test with interactive or piped commands:

```bash
echo "/bin/ls" | ./hsh
```

```bash
cat test_file | ./hsh
```

## 👨‍💻 Authors

- [@TonNomGitHub](https://github.com/TonNomGitHub)
- [@PartenaireGitHub](https://github.com/PartenaireGitHub)

```
