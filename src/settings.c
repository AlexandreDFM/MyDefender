/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** settings
*/

#include "my_defender.h"

void settings(sfRenderWindow *win, defender_t *defender)
{
    if (sfMusic_getStatus(defender->menu_music) == 0)
        sfMusic_play(defender->menu_music);
    display_go(win, defender->menu);
}
