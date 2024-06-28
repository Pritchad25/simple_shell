# Project Title: C - Simple Shell

## Table of Contents
1. About
2. Learning Objectives
3. Requirements
4. Getting Started
5. Usage
6. Contributing
7. License

## About <a name="about"></a>
This project is part of the curriculum of the ALX Software Engineering program and is the CapStone project to wrap up the First Trimester of the program, where the main focus was on Low Level Programming. The goal of this project was to implement a Unix-like Shell command intepreter.

## Learning Objectives <a name="learning-objectives"></a>
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of `main`
- How does the shell use the `PATH` to find the programs
- How to execute another program with the `execve` system call
- How to suspend the execution of a process until one of its children terminates
- What is `EOF` / “end-of-file”?

## Requirements <a name="requirements"></a>
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style linter.
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to
- Write a `README` with the description of your project
- You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. 

## Getting Started <a name="getting-started"></a>
1. Clone this repository: `git clone https://github.com/Pritchad25/simple_shell.git`
2. Run any executable file in the directory, which is the file `hsh`

## Usage <a name="usage"></a>
## Compilation <a name="compilation"></a>
Your shell will be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
## Testing <a name="testing"></a>
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Output <a name="output"></a>
- Unless specified otherwise, your program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below)
Example of error with `sh`:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program `hsh`:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## Contributing <a name="contributing"></a>
[Freeman Ncube](https://www.github.com/freezah65) and I partnered up for this project.However, pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License <a name="license"></a>
ALX 2024 - [alxafrica](https://www.alxafrica.com)
