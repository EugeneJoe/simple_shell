#ifndef SHELLHEADER_H
#define SHELLHEADER_H

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

#define BUFSIZE 1024
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

int _putchar(char c);
int display_help(char **cmd, __attribute__((unused))int er);
int printenv(char **env);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src, char *src2, char *src3);
int check_path(char **args, char **env);
int _strlen(char *str);
char *_strdup(char *str);
char *_strtok(char *str, const char *delim);
void handle_sigint(int sig);
int _setenv(char *var, char *value, char **env);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _unsetenv(char *var, char **env);
int _cd(char **args, char **env);
char *_getenv(char *var, char **env);
int *check_args(char **args, char **env);
char *_strchr(char *s, char c);
char *tostring(int num);
void free_2d(char **array);
char *buildstr(char *str1, char *str2, char *str3);
char **parsecommand(char *command);
int built_in(char **args, char **env);
void shell_exit(char **args, char **env, char *command);
int toint(char *str);
int exec_func(char **args, char **env, char **argv);
int history(char *input);
void free_env(char **env);
int disp_hist(__attribute__((unused))char **c, __attribute__((unused))int s);
void *fill_an_array(void *a, int el, unsigned int len);
void hash_handle(char *buff);
char *_getline(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
