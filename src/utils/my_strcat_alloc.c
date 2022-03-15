/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** my_strcat_alloc
*/

#include "my_defender.h"

char *my_strcat_alloc(char *dest, char const *src)
{
    int i = 0;
    char *dest2 = malloc(sizeof(char) *
    (my_strlen(dest) + my_strlen(src) + 1));
    dest2[my_strlen(dest) + my_strlen(src)] = '\0';
    while (dest[i] != '\0') {
        dest2[i] = dest[i];
        i += 1;
    }
    int j = 0;
    while (src[j] != 0) {
        dest2[i + j] = src[j];
        j += 1;
    }
    dest2[i + j] = '\0';
    return (dest2);
}
