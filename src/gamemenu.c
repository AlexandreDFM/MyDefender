/*
** EPITECH PROJECT, 2021
** menu
** File description:
** Display Functions for Menu
*/

#include "my_defender.h"

void is_bouton(sfRenderWindow *window, defender_t *defender)
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

void switch_window(sfRenderWindow *window, defender_t *defender)
{
    if (defender->event.mouseButton.type == sfEvtMouseButtonReleased
    && defender->event.mouseButton.button == sfMouseLeft)
    {
        if (defender->valid[0])
            defender->scene = GAME;
        if (defender->valid[3])
            sfRenderWindow_close(window);
    }
}

void menu(sfRenderWindow *window, defender_t *defender)
{
    display_go(window, defender->menu);
    display_go(window, defender->title);
    is_bouton(window, defender);
    switch_window(window, defender);
    for (int i = 0; i < 4; i++)
        display_bouton(window, defender->bouton[i]);
}
