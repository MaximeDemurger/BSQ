/*
** EPITECH PROJECT, 2019
** free tab
** File description:
** tab free
*/

#include "bsq.h"

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        free(tab[i]);
        i++;
    }
    free(tab);
}