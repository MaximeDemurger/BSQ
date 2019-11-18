/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "bsq.h"

int str_is_num(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '\n')
                return 1;
        i++;
    }
    return 0;
}

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
        if (str_is_num(tab[0]) == 1)
            return -1;
        j = 0;
        while (tab[i][j]) {
            if (tab[i][j] != '.' && tab[i][j] != 'o' &&
            tab[i][j] != '\n')
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

    if (!fd || ac < 1) return 84;
    tab = put_in_tab(fd);
    result = copy_tab(tab);
    if (check_error(tab) == 0) {
        size = bsq(tab, &i, &j);
        printing_square(result, i, j, size);
    } else {
        write(1, "Wrong Map\n", 10);
        return 84;
    }
    free_tab(tab);
    free_tab(result);
    return 0;
}