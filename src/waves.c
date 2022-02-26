/*
** EPITECH PROJECT, 2022
** waves
** File description:
** waves
*/

#include "my_defender.h"

void fill_waves(game_t *game)
{
    void (*func_array[])(bloons_t *bloon) = {red_bloons, blue_bloons, green_bloons, yellow_bloons};
    int i = game->wave_ind, j = 0;
    int count = 0;
    for (; game->waves[i][0] != '#'; i++) {
        if (my_str_isnum(game->waves[i])) count += my_atoi(game->waves[i]);
    }
    for (int i = 0; i < count; i++) fill_bloons(game);
    game->bloon = game->head;
    for (i = game->wave_ind; game->waves[i][0] != '#'; i++) {
        for (j = 0; game->waves[i][0] != game->b_colors[j] && game->b_colors[j] != 0; j++);
        i++;
        count = my_atoi(game->waves[i]);
        for (int ind = 0; ind < count; ind++) {
            func_array[j](game->bloon);
            game->bloon = game->bloon->next;
        }
        count = 0;
    }
    game->bloon = game->head;
    game->wave_ind = i + 1;
}

char **init_waves(void)
{
    int i = 1, wave = 0, j = 0;
    int count = 1;
    char **tmp = my_strtwa(get_lines("maps/wave"), "|\n");
    return tmp;
}
