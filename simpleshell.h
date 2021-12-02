#ifndef DEF_SIMPLESHELL
#define DEF_SIMPLESHELL

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

/* Manage strings of characters */
int _putchar(char c);
int _putstr(char *s);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);

/* Parse and execute and get env and path*/
char **split(char *line, char *delim);
void exe(char **av);
void get_path(char **av);
char *_getenv(const char *name);

/* Manage memory */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif /*DEF_SIMPLESHELL*/
