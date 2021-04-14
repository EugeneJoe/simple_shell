#ifndef SHELBERTON_H
#define SHELBERTON_H

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

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
int exec_func(char **args, char **env, char *command);
void piped(char **my_env);

#endif
