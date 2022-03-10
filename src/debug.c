/*
** EPITECH PROJECT, 2022
** debug
** File description:
** Function relatives to debug defender
*/

#include "my_defender.h"

void d_towerhud_hitbox(sfRenderWindow *w, game_t *g)
{
    for (int i = 0; i < 14; i++)
        sfRenderWindow_drawRectangleShape(w, g->tower_hitbox[i].shape, NULL);
}
