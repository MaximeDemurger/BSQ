/*
** EPITECH PROJECT, 2018
** convert
** File description:
** converts ints to char *
*/

#include "bsq.h"

char *convert_to_string(int nb)
{
    char *string = malloc(sizeof(char) * 3);
    int i = 0;

    if (nb == 0)
        string[i] = '0';
    while (nb > 0) {
        string[i] = (nb % 10)  + 48;
        nb = nb/ 10;
        i++;
    }
    string[i] = '\0';
    return (my_revstr(string));
}
