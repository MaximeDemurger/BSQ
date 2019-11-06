/*
** EPITECH PROJECT, 2019
** put
** File description:
** in tab
*/

#include "bsq.h"

char **put_in_tab(int fd)
{
    char **tab = NULL;
    char buffer[100000 + 1];

    read(fd, buffer, 100000);
    tab = my_str_to_word_array(buffer, '\n');
    return tab;
}