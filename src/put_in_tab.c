/*
** EPITECH PROJECT, 2019
** put
** File description:
** in tab
*/

#include "bsq.h"

char **put_in_tab(int fd, char **av)
{
    char **tab = NULL;
    struct stat sb;
    char *buffer;

    stat(av[1], &sb);
    if (sb.st_size > 1000000)
        return 0;
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    if (read(fd, buffer, sb.st_size) == 0)
        return NULL;
    tab = my_str_to_word_array(buffer, '\n');
    return tab;
}