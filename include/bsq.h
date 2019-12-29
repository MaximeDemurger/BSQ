/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq
*/

#ifndef BSQ_H
#define BSQ_H

#include "stddef.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_strlen(char const *str);
void free_tab(char **tab);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *str);
char **put_in_tab(int fd, char **av);
char **my_str_to_word_array(char const *str, char separator);
int bsq(char **tab, int *, int *);
int printing_square(char **result, int i, int j, int size);
int my_atoi(char const *stack);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char *src, int n);
char *convert_to_string(int nb);
char *my_revstr(char *str);


#endif /* !BSQ_H */
