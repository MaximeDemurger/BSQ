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
    int j = 0;

    while (result[i]) {
        j = 0;
        while (result[i][j]) {
            write(1, &result[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
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
    return 0;
}