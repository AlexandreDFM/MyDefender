/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** settings
*/

#include "my_defender.h"

void is_bouton_3(sfRenderWindow *window, defender_t *defender)
{
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    for (int i = 0; i < 4; i++) {
        sfFloatRect b = {defender->bouton[i].pos.x, defender->bouton[i].pos.y,
        defender->bouton[i].rect.width * defender->bouton[i].resize.x,
        defender->bouton[i].rect.height * defender->bouton[i].resize.y};
        defender->valid[i] = sfFloatRect_contains(&b, posmousex, posmousey);
        if (defender->valid[i] == 1 && sfMouse_isButtonPressed(sfMouseLeft))
            defender->bouton[i].rect.left = 318;
        else if (defender->valid[i] == 1)
            defender->bouton[i].rect.left = 159;
        else
            defender->bouton[i].rect.left = 0;
    }
}

void switch_window_3(sfRenderWindow *window, defender_t *defender)
{
    if (defender->event.mouseButton.type == sfEvtMouseButtonReleased
    && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->valid[0]) {
            sfMusic_stop(defender->menu_music);
            defender->scene = GAME;
        }
        if (defender->valid[1]) {
            defender->scene = SETTINGS;
        }
        if (defender->valid[2]) {
            defender->scene = HOW_TO_PLAY;
        }
        if (defender->valid[3]) {
            sfRenderWindow_close(window);
        }
    }
}

void settings(sfRenderWindow *win, defender_t *defender)
{
    if (sfMusic_getStatus(defender->menu_music) == 0)
        sfMusic_play(defender->menu_music);
    display_go(win, defender->menu);
}
