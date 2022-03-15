/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pasue
*/

#include "my_defender.h"

void p_draw(sfRenderWindow *win, defender_t *defender, game_t *game)
{
    sfRenderWindow_drawSprite(win, game->map, NULL);
    while (game->bloon != NULL && game->bloon->next != NULL) {
        if (sfFloatRect_contains(&game->frame,
        game->bloon->pos.x, game->bloon->pos.y)) {
            sfRenderWindow_drawSprite(win, game->bloon->sprite, NULL);
        }
        game->bloon = game->bloon->next;
    }
    sfRenderWindow_drawSprite(win, game->hud, NULL);
    sfRenderWindow_drawSprite(win, game->up_gui, NULL);
    sfRenderWindow_drawSprite(win, game->p_but[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, game->p_but[1].sprite, NULL);
}

void check_but(sfRenderWindow *win, defender_t *defender, game_t *game, int i)
{
    switch (i) {
    case 0:
        defender->scene = GAME;
    case 1:
        break;
    case 2:
        defender->scene = MENU;
    case 3:
        break;
    case 4: case 5: case 6:
        if (i == 4)
            defender->aplay = defender->aplay == 1 ? 0 : 1;
        defender->p_menu.pause_b[i].rect.left +=
        (defender->p_menu.pause_b[i].rect.left == 0 ||
        defender->p_menu.pause_b[i].rect.left == 252) ? 126 : -126;
    }
}

void pause_buttons(sfRenderWindow *w, defender_t *d, game_t *game, int i)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(w);
    d->cursor.pos.x = pos.x;
    d->cursor.pos.y = pos.y;
    sfFloatRect rect =
    sfSprite_getGlobalBounds(d->p_menu.pause_b[i].sprite);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        d->p_menu.pause_b[i].clicked = 1;
        sfSprite_setScale(d->p_menu.pause_b[i].sprite,
        (sfVector2f) {1.1, 1.1});
        if (sfMouse_isButtonPressed(sfMouseLeft) && d->state == 0) {
            d->state = 1;
            check_but(w, d, game, i);
        }
    } else {
        d->p_menu.pause_b[i].clicked = 0;
        sfSprite_setScale(d->p_menu.pause_b[i].sprite,
        (sfVector2f) {1, 1});
    }
    if (d->state != 0 && d->event.type ==
        sfEvtMouseButtonReleased &&
        d->event.mouseButton.button == sfMouseLeft) {
            d->state = 0;
    }
}

void pause_f(sfRenderWindow *win, defender_t *defender, game_t *game)
{
    p_draw(win, defender, game);
    sfRenderWindow_drawRectangleShape(win, defender->p_menu.fade, NULL);
    draw_score(win, game, defender);
    for (int i = 0; i < 8; i++) {
        pause_buttons(win, defender, game, i);
        sfSprite_setTextureRect(defender->p_menu.pause_b[i].sprite,
        defender->p_menu.pause_b[i].rect);
        sfRenderWindow_drawSprite(win,
        defender->p_menu.pause_b[i].sprite, NULL);
    }
    game->bloon = game->head;
}
