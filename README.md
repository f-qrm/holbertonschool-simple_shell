# 🐚 Simple Shell Project

<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

## Table of Contents {#table-of-contents}

- [Description](#-description)
- [Requirements](#requirements)
- [Authorized Functions](#-authorized-functions)
- [File Structure](#file-structure)
- [Compilation](#compilation)
- [Manual Page](#-manual-page)
- [Usage](#usage)
- [Interactive Mode](#-interactive-mode)
- [Non-Interactive Mode](#-non-interactive-mode)
- [Learning Objectives](#-learning-objectives)
- [Features](#-features)
- [Flowchart](#-flowchart)
- [Testing](#-testing)
- [Authors](#-authors)
  
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

---

## 🔧 Authorized Functions

- access
- chdir
- close
- closedir, 
- execve, 
- exit, 
- _exit, 
- fflush, 
- fork, 
- free,
- getcwd, 
- getline, 
- getpid, 
- isatty, 
- kill, 
- malloc, 
- open, 
- opendir, 
- perror,
- printf, 
- fprintf, 
- vfprintf, 
- sprintf, 
- putchar, 
- read, 
- readdir, 
- signal, 
- stat,
- lstat, 
- fstat, 
- strtok, 
- wait, 
- waitpid, 
- wait3, 
- wait4, 
- write

---

## File Structure

- ├── main.c             # Entry point, handles the shell loop
- ├── prompt.c           # Prompt logic (display and read input)
- ├── parser.c           # Parses the input command line
- ├── executor.c         # Executes commands using fork + execve
- ├── path.c             # Searches command in PATH
- ├── env.c              # Handles environment (get, print, set)
- ├── shell.h            # Function prototypes and shared headers
- ├── man_1_hsh.1        # Manual page for the shell
- ├── .gitignore
- └── README.md


---

##  Compilation

You can compile the shell with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```
## Usage

### 🔹 Interactive Mode
```
<pre>$ ./shell
($) ls -l
total 16
-rw-r--r-- 1 user user 1234 main.c
($) exit</pre>
```
---

### 🔹 Non-Interactive Mode
```
<pre> $ echo "ls -l" | ./shell
total 16
-rw-r--r-- 1 user user 1234 main.c</pre>
```
---
## 🧪 Testing
Test the shell in both modes:

##### Interactive:
```
  <pre>$ ./shell
  ($) ls
  ($) /bin/ls
  ($) exit</pre>
```
##### Non-Interactive:
```
  $ echo "/bin/ls" | ./shell
  file1  file2  shell
```
##### Using a file:
```
  $ cat commands.txt
  ls
  env
  exit
  $ ./shell < commands.txt
```
## 📚 Learning Objectives

By completing this project, you will be able to:

- Explain what happens when you type a command into a shell
- Differentiate between functions and system calls
- Use and manage environment variables
- Handle processes using fork, execve, and wait
- Parse input with getline and strtok
- Detect end-of-file (EOF) in both interactive and non-interactive modes
- Implement basic built-in commands like exit and env

-----

## 🧠 Features

| Feature              | Description                                               |
|----------------------|-----------------------------------------------------------|
| Command execution    | Runs executables from PATH or direct path                |
| PATH resolution      | Locates commands using the system’s PATH variable         |
| Environment support  | Built-in `env` displays the environment variables         |
| Built-in commands    | Supports `exit`, `env`, and handles invalid commands      |
| Interactive mode     | Displays a prompt and waits for user input                |
| Non-interactive mode | Accepts and executes commands from a file or a pipe       |
| Error handling       | Gracefully handles errors with relevant messages          |

--- 

##  Example Built-ins
```
<pre>($) env
PATH=/usr/local/bin:/usr/bin:/bin
HOME=/home/user
PWD=/home/user/shell
($) exit</pre>
```
--- 

## 📖 Manual Page

## Prerequisites

- **Git**  
- **Superuser (root)** access  
- **Basic terminal** knowledge  

## Installation Steps

1. **Clone the Repository**  
   ```bash
   git clone https://github.com/your-username/your-repository.git
   cd your-repository
---

#### 2. Prepare the Installation Script
```bash
chmod +x install_man_page.sh
```
#### 3. Run the Installation Script
```bash
sudo ./install_man_page.sh
```
#### Verifying Installation
```bash
man myshell
```
### Troubleshooting
- Ensure necessary permissions
- Verify script location
- Check `mandb` installation

### Uninstallation
```bash
sudo rm /usr/local/share/man/man1/myshell.1.gz
sudo mandb
```
## 🔄 Flowchart

--------------


## 🧑‍💻 Authors

- Fjolla [@Fjolla-github](https://github.com/f-qrm)
- Alexis [Alexis-github](https://github.com/alexiscnl)
