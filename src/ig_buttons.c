/*
** EPITECH PROJECT, 2021
** menu
** File description:
** Display Functions for Menu
*/

#include "my_defender.h"

void ig_but3(game_t *g, defender_t *defender, sfRenderWindow *win, int i)
{
    if (g->p_but[i].clicked == 1 && sfMouse_isButtonPressed(sfMouseLeft)
    && defender->playing == 1 && defender->state == 0 && i == 0) {
        defender->state = 3;
    }
    if (g->p_but[i].clicked == 1 && sfMouse_isButtonPressed(sfMouseLeft)
    && defender->state == 0 && i == 1) defender->scene = PAUSE;
    if (defender->state != 0 && defender->event.type ==
    sfEvtMouseButtonReleased &&
    defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->state == 3) {
            g->ff = (g->ff == 1 && defender->playing == 1) ? 2 : 1;
            g->p_but[i].rect.left =
            (g->p_but[i].rect.left == 126) ? 252 : 126;
            sfSprite_setTextureRect(g->p_but[i].sprite,
            g->p_but[i].rect);
        }
    defender->state = 0;
    }
}

void ig_but2(game_t *g, defender_t *defender, sfRenderWindow *win, int i)
{
    if (g->p_but[i].clicked == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) &&
        defender->playing == 0 && i == 0) {
            if (defender->state == 4) fill_waves(g);
            defender->state = 1;
            defender->playing = 1;
            g->p_but[i].rect.left = (g->ff == 1) ? 126 : 252;
            sfSprite_setTextureRect(g->p_but[i].sprite, g->p_but[i].rect);
        }
}

void ig_but(game_t *g, defender_t *defender, sfRenderWindow *win)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    defender->cursor.pos.x = pos.x;
    defender->cursor.pos.y = pos.y;
    for (int i = 0; i < 2; i++) {
        sfFloatRect rect = sfSprite_getGlobalBounds(g->p_but[i].sprite);
        if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
            g->p_but[i].clicked = 1;
            sfSprite_setScale(g->p_but[i].sprite, (sfVector2f) {0.6, 0.6});
        } else {
            g->p_but[i].clicked = 0;
            sfSprite_setScale(g->p_but[i].sprite, (sfVector2f) {0.5, 0.5});
        }
        ig_but2(g, defender, win, i);
        ig_but3(g, defender, win, i);
    }
}
