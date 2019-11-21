/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** revstr
*/

#include "bsq.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char c;

    while (i < len) {
        c = str[i];
        str[i] = str[len];
        str[len] = c;
        i++;
        len--;
    }
    return str;
}
