/*
** EPITECH PROJECT, 2021
** menu
** File description:
** Display Functions for Menu
*/

#include "my_defender.h"

void check_mouse(sfRenderWindow *window, defender_t *defender)
{
    sfFloatRect play = {sfSprite_getPosition(defender->bouton[0].sprite).x,
    sfSprite_getPosition(defender->bouton[0].sprite).y, 159 * 2, 43 * 2};
    sfFloatRect options = {sfSprite_getPosition(defender->bouton[1].sprite).x,
    sfSprite_getPosition(defender->bouton[1].sprite).y, 159 * 2, 43 * 2};
    sfFloatRect credit = {sfSprite_getPosition(defender->bouton[2].sprite).x,
    sfSprite_getPosition(defender->bouton[2].sprite).y, 159 * 2, 43 * 2};
    sfFloatRect exit = {sfSprite_getPosition(defender->bouton[3].sprite).x,
    sfSprite_getPosition(defender->bouton[3].sprite).y, 159 * 2, 43 * 2};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    defender->valid[0] = sfFloatRect_contains(&play, posmousex, posmousey);
    defender->valid[1] = sfFloatRect_contains(&options, posmousex, posmousey);
    defender->valid[2] = sfFloatRect_contains(&credit, posmousex, posmousey);
    defender->valid[3] = sfFloatRect_contains(&exit, posmousex, posmousey);
}

void change_bouton_rect(sfRenderWindow *window, defender_t *defender)
{
    if (defender->valid[0] == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        defender->bouton[0].rect.left = 159 + 159;
    else if (defender->valid[0] == 1)
        defender->bouton[0].rect.left = 159;
    else
        defender->bouton[0].rect.left = 0;
    if (defender->valid[1] == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        defender->bouton[1].rect.left = 159 + 159;
    else if (defender->valid[1] == 1)
        defender->bouton[1].rect.left = 159;
    else
        defender->bouton[1].rect.left = 0;
    if (defender->valid[2] == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        defender->bouton[2].rect.left = 159 + 159;
    else if (defender->valid[2] == 1)
        defender->bouton[2].rect.left = 159;
    else
        defender->bouton[2].rect.left = 0;
    if (defender->valid[3] == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        defender->bouton[3].rect.left = 159 + 159;
    else if (defender->valid[3] == 1)
        defender->bouton[3].rect.left = 159;
    else
        defender->bouton[3].rect.left = 0;
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
    display_menu(window, defender->menu);
    display_title(window, defender->title);
    check_mouse(window, defender);
    change_bouton_rect(window, defender);
    switch_window(window, defender);
    for (int i = 0; i < 4; i++)
        display_bouton(window, defender->bouton[i]);
}
