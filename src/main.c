/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "bsq.h"

int tab_size(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i;
}

char **copy_tab(char **tab)
{
    char **result = malloc(sizeof(char *) * tab_size(tab) + 1);
    int i = 0;
    int f = 0;

    if (!result)
        return NULL;

    while (tab[i]) {
        result[f] = my_strdup(tab[i]);
        f++;
        i++;
    }
    return result;
}

int check_error(char **tab)
{
    int i = 1;
    int j = 0;

    while (tab[i]) {
        j = 0;
        while (tab[i][j]) {
            if (tab[i][j] != '.' && tab[i][j] != 'o')
                return -1;
            j++;
        }
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char **tab = NULL;
    char **result = NULL;
    int i = 0;
    int j = 0;
    int size;

    if (!fd) return 1;
    tab = put_in_tab(fd);
    result = copy_tab(tab);
    if (check_error(tab) == -1)
        return 84;
    else {
        size = bsq(tab, &i, &j);
        printing_square(result, i, j, size);
    }
    return 0;
}