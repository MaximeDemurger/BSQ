/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq
*/

#include "bsq.h"


int chose_little(char **tab, int i, int j)
{
    int diag = tab[i - 1][j - 1] - 48;
    int top = tab[i - 1][j] - 48;
    int left = tab[i][j - 1] - 48;
    int k = 0;

    (diag > left && left < top) ? (k = left) :
    (diag < left && diag < top) ? (k = diag) :
    (diag > top && left > top) ? (k = top) :
    (diag == top && top == left && left == diag) ? (k = top) :
    (diag > 1 && top <= left) ? (k = top) :
    (top > 1 && diag <= left) ? (k = diag) :
    (left > 1 && top <= diag) ? (k = top) : 0;
    return k;
}

char **modifing_square(char **tab)
{
    int i = 1;
    int j = 0;

    while (tab[i]) {
        j = 0;
        while (tab[i][j]) {
            if (tab[i][j] == 'o')
                tab[i][j] = '0';
            if (tab[i][j] == '.' && i == 1)
                tab[i][j] = '1';
            if ((tab[i][j] == '.') && (i > 1))
                tab[i][j] = (1 + chose_little(tab, i, j)) + 48;
            j++;
        }
        i++;
    }
    return tab;
}

int bsq(char **tab, int *i, int *j)
{
    int size = 0;
    int x = 1;
    int y = 0;

    tab = modifing_square(tab);
    while (tab[x]) {
        y = 0;
        while (tab[x][y]) {
            if (size < (tab[x][y] - 48)) {
                size = tab[x][y] - 48;
                *i = x;
                *j = y;
            }
            y += 1;
        }
        x += 1;
    }
    return size;
}