/*
** EPITECH PROJECT, 2019
** strncpy
** File description:
** strncpy
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != 0 && i < n) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
