# Introduction

The files in this repository are functions and programs that deal with
setting up a UNIX command line interpreter.

  - Usage: simple_shell

The shell:
1. Displays a prompt and waits for the user to type a command. Command lines
   always end with a new line.
2. Displays a prompt again each time a command has been executed.
3. If an executable cannot be found, an error message is displayed, followed
   by a prompt.
4. Handles the "end-of-file" condition (CTRL+D)

## buildstr.c

Takes 3 pointers to strings and concatenates them to from a complete string.
Creates a buffer using malloc to concatenate the passed strings to.
Returns a pointer to a string that should be freed by the caller.

## built_in_shell.c

Checks for whether the passed commands are part of the built_in shell functions.
If a match is found, that function is run using the passed arguments, if any.

## cd.c

One of the shell built_in functions. Changes the directory we're currently in,
and updates the PWD and OLDPWD environment variables.

## check_args.c

Checks the arguments passed for the echo command and does the
required substitution. If no substitution is required, the argument remains
unchanged.

## check_path.c

Checks for the location of a passed command in the directories listed in the
path variable. If the command is found, the full path string is built using the
buildstr.c function.

## exec_function.c

Runs the passed command using the arguments given. First checks whether the
command is a built_in shell function using the built_in_shell.c function.
If not, it searches for the command using the check_path.c function. If a match
is found, it creates a child process and runs the command in the child process.
If no match is found even in the current directory, the function fails.

## free_2d.c

Frees an array of char arrays that were created using malloc.

## getenv.c

Retrieves the value of an environment variable. Checks whether the passed
environment variable exists. If so, it returns its value. If no match is found,
it returns NULL.

## handle_sigint.c

Handles the SIGINT signal (Ctrl c or ^C) using the signal function.
If SIGINT is recieved, it prints a newline and a prompt and waits for more
user input.

## parsecommands.c

Parses the string that has been read from the command line. Separates the string
into its constituent words using space as a delimiter and stores the words in
an array of words. This 2d array is created using malloc and thus should be
freed once used. Returns this 2d array.

## printenv.c

Prints the environment variables to stdout when the "env" command is received.

## setenv.c

Creates a new environment variable and sets its value or updates the value of an
existing environment variable when the setenv command is received.

## shelberton.h

Header file for the shell program. Contains all the function prototyes as well
as the include statements for all the required header files.

## shell.c

Contains the main function for the shell program. Reads in the command and
arguments from stdin and calls the necessary functions to parse the string and
run the command. Also sets up the environment variables that will be used.

## shell_exit.c

Called when the exit command is passed. It frees all the malloc'ed variables and
then exits the shell with the given status, or 0 if none is given.

## strcat.c

Our implementation of the strcat function. Takes 4, arguments; 1 destination
string and 3 source strings. The destination string should be large enough to
fit all the passed strings.

## strchr.c

Our implementation of the strchr.c function. It finds the first occurence of a
given character in a given string. If not found, it returns NULL.

## strcmp.c

Our implementation of the strcmp function. It takes 2 pointers to strings as
arguments and compares them. If the 2 strings match, it returns 0.
If a mismatch is found, it returns the difference in the ASCII codes of the
mismatched characters.

## strdup.c

Our implementation of the strdup function. It takes a pointer to a string as an
argument. It creates a buffer of required size using malloc and copies the
given string to the buffer and returns a pointer to the created buffer.
Calling function should free the return value.

## strlen.c

Takes a pointer to a string and returns the length of the string.

## strncmp.c

Our implementation of the strncmp function. Compares the first n bytes of the
2 strings it receives and returns 0 if they match. If a mismatch is found, it
returns the difference in ASCII codes of the mismatched characters.

## strtok.c

Our implementation of the strtok function. It parses a given string using the
given delimeter character and returns a pointer to the resulting string.
Uses malloc and thus the calling function should free the returned pointer.

## toint.c

Takes in a nunmber contained in a string and returns it as an integer variable.

## tostring.c

Takes an integer variable as an argument and converts it to a string. Returns a
pointer to this string. Uses malloc to create the buffer to store the number,
thus the calling function should free the returned pointer.

## unsetenv.c

Removes an existing environment variable. Called when the "unset" command
is received.
