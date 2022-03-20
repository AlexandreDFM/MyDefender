/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

void init_special(defender_t *defender, game_t *g)
{
    g->tower_stats = my_strtwa(get_lines("./parsing/tower_stats.txt"), "\n");
    g->monkey = NULL;
    g->monkey_head = NULL;
    g->t_monkey = sfTexture_createFromFile("./sprites/all_monkey.png", NULL);
    fill_hudtowers(g);
    fill_r_to(g);
    g->gameoverscreen = c_r_hitbox((sfVector2f) {0, 0}, (sfIntRect)
    {0, 0, 1920, 1029}, (sfVector2f) {1, 1}, (sfColor) {0, 0, 0, 100});
}
