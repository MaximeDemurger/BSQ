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
    char *copy_first = malloc(sizeof(char) * (my_strlen(tab[0]) - 2));

    copy_first = my_strncpy(copy_first, tab[0], my_strlen(tab[0]) - 2);
    if (str_is_num(tab[0]) == 1)
        return 84;
    while (tab[i]) {
        j = 0;
        while (tab[i][j]) {
            if (tab[i][j] != '.' && tab[i][j] != 'o' &&
            tab[i][j] != '\n')
                return 84;
            j++;
        }
        i++;
    }
    if (my_strcmp(convert_to_string(i - 2), copy_first) < 0)
        return 84;
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

    if (fd == -1 || ac < 2) return 84;
    if ((tab = put_in_tab(fd)) == NULL)
        return 84;
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