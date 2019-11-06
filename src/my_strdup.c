/*
** EPITECH PROJECT, 2019
** strdup
** File description:
** strdup
*/

#include "stdlib.h"
#include "bsq.h"

char *my_strdup(char *str)
{
    int i = my_strlen(str) + 1;
    char *dup = malloc(sizeof(char) * i);

    if (!dup)
        return NULL;
    dup = my_strcpy(dup, str);
    dup[i - 1] = 0;
    return dup;
}
