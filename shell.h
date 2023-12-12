#ifndef __SHELL_H__
#define __SHELL_H__

/**
 * this header file contains the declaration of
 * the functions used in this main program
 * it also includes the necessary headers for sepicific
 * functionalities, such as system
 * functions and external variables
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100
#define TOKEN_BUFFER_SIZE 64

extern char **environ; /* Declaration of the environ variable */

void myprint(char *msg);
void display_prompt(void);
void execute_command(char *command);
void shell_loop(void);
char **tokenize(char *command);
void free_tokens(char **tokens);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *accept);

#endif
