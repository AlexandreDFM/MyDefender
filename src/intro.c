/*
** EPITECH PROJECT, 2022
** intro
** File description:
** Function about intro of the game
*/

#include "my_defender.h"

void move_rectintro(defender_t *defender, sfIntRect *rect, int modify, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = modify;
        defender->scene = MENU;
    } else {
        rect->left += modify;
    }
}

void intro_clock(defender_t *defender)
{
    if (sfClock_getElapsedTime(defender->clockintro).microseconds > 100000.0) {
        move_rectintro(defender, &defender->intro.rect, 383, 12256);
        sfClock_restart(defender->clockintro);
    }
}

void intro(sfRenderWindow *window, defender_t *defender)
{
    intro_clock(defender);
    display_go(window, defender->intro);
}
