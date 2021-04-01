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
