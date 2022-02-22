/*
** EPITECH PROJECT, 2022
** texture
** File description:
** texture
*/

#include "my_defender.h"

char *fill_map(char const *filepath, int total_len)
{
    char *line_buff = NULL;
    char *map = malloc(sizeof(char) * total_len + 1);
    memset(map, 0, total_len + 1);
    size_t buff_size = 0;
    int line_count = 0, line_len = 0;
    FILE *fp = fopen(filepath, "r");
    line_len = getline(&line_buff, &buff_size, fp);
    while (line_len >= 0) {
        map = my_strcat(map, line_buff);
        line_count++;
        line_len = getline(&line_buff, &buff_size, fp);
    }
    free(line_buff);
    return map;
}

char *get_lines(char const *filepath)
{
    char *line_buff = NULL;
    size_t buff_size = 0;
    int line_count = 0, line_len = 0, total_len = 0;
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        my_printf("Wrong Map\n");
        return NULL;
    }
    line_len = getline(&line_buff, &buff_size, fp);
    while (line_len >= 0) {
        total_len += line_len;
        line_count++;
        line_len = getline(&line_buff, &buff_size, fp);
    }
    free(line_buff);
    fclose(fp);
    return fill_map(filepath, total_len);
}
