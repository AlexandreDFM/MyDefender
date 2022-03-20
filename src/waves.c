/*
** EPITECH PROJECT, 2022
** waves
** File description:
** waves
*/

#include "my_defender.h"

void end_fill_waves(game_t *g, int i)
{
    g->bloon = g->head;
    g->wave_ind = i + 1;
    g->wave_nb += 1;
}

void fill_waves(game_t *g)
{
    void (*func_array[])(bloons_t *bloon) =
    {red_bloons, blue_bloons, green_bloons, yellow_bloons};
    int i = g->wave_ind, j = 0, count = 0;
    for (; g->waves[i][0] != '#'; i++) {
        if (my_str_isnum(g->waves[i])) count += my_atoi(g->waves[i]);
    }
    for (int i = 0; i < count; i++) fill_bloons(g);
    g->bloon = g->head;
    for (i = g->wave_ind; g->waves[i][0] != '#'; i++) {
        for (j = 0; g->waves[i][0] != g->b_colors[j]
        && g->b_colors[j] != 0; j++);
        i++, count = my_atoi(g->waves[i]);
        for (int ind = 0; ind < count; ind++) {
            func_array[j](g->bloon);
            g->bloon = g->bloon->next;
        }
        count = 0;
    }
    end_fill_waves(g, i);
}

char **init_waves(void)
{
    char **tmp = my_strtwa(get_lines("maps/wave"), "|\n");
    return tmp;
}
