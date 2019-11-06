/*
** EPITECH PROJECT, 2019
** printing square
** File description:
** printing square
*/

#include "bsq.h"

void print(char **result)
{
    int i = 1;

    while (result[i]) {
        printf("%s\n", result[i++]);
    }
}

int printing_square(char **result, int i, int j, int size)
{
    int x = i - size;
    int y = j - size;
    int j_value = j;

    while (i > x) {
        j = j_value;
        while (j > y) {
            result[i][j] = 'x';
            j--;
        }
        i--;
    }
    print(result);
}