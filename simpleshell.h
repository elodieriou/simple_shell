#ifndef DEF_SIMPLESHELL
#define DEF_SIMPLESHELL

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

/**
 * struct builtin_shell - Struct that use a builtin
 * @name: the name of the command
 * @f: the fonction associated to the command
 */
typedef struct builtin_shell
{
	char *name;
	int (*f)(char **);
} builtin_t;

extern char **environ;

/* Manage strings of characters */
int _putchar(char c);
int _putstr(char *s);
int _strcmp(char *s1, const char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* Parse, execute, get environment and get path*/
char **split(char *line, char *delim);
int exe(char **av);
void get_path(char **av);
char *_getenv(const char *name);

/* Manage memory */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);

/* Builtins */
int exe_builtins(char **av);
int check_builtin(char **av);
int builtin_exit(char **av);
int builtin_env(char **av);
int builtin_help(char **av);

#endif /*DEF_SIMPLESHELL*/
