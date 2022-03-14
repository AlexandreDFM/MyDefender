/*
** EPITECH PROJECT, 2022
** how_to_play
** File description:
** Function to display the how to play
*/

#include "my_defender.h"

void how_to_play(sfRenderWindow *win, defender_t *defender)
{
    if (sfMusic_getStatus(defender->menu_music) == 0)
        sfMusic_play(defender->menu_music);
    display_go(win, defender->menu);
    sfRenderWindow_drawText(win, defender->help_txt, NULL);
}
