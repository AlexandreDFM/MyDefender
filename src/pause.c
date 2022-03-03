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
        if (sfFloatRect_contains(&game->frame, game->bloon->pos.x, game->bloon->pos.y)){
            sfRenderWindow_drawSprite(win, game->bloon->sprite, NULL);
        }
        game->bloon = game->bloon->next;
    }
    sfRenderWindow_drawSprite(win, game->hud, NULL);
    sfRenderWindow_drawSprite(win, game->up_gui, NULL);
    sfRenderWindow_drawSprite(win, game->p_but[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, game->p_but[1].sprite, NULL);
}

void pause_buttons(sfRenderWindow *win, defender_t *defender, game_t *game, int i)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    defender->cursor.pos.x = pos.x;
    defender->cursor.pos.y = pos.y;
    if (i < 5) {
        sfFloatRect rect =
        sfSprite_getGlobalBounds(defender->p_menu.pause_b[i].sprite);
        if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
            defender->p_menu.pause_b[i].clicked = 1;
        } else defender->p_menu.pause_b[i].clicked = 0;
        if (defender->p_menu.pause_b[i].clicked == 1) {
            sfSprite_setScale(defender->p_menu.pause_b[i].sprite, (sfVector2f) {1.1, 1.1});
        } else {
            sfSprite_setScale(defender->p_menu.pause_b[i].sprite, (sfVector2f) {1, 1});
        }
    }
}

void pause_f(sfRenderWindow *win, defender_t *defender, game_t *game)
{
    p_draw(win, defender, game);
    sfRenderWindow_drawRectangleShape(win, defender->p_menu.fade, NULL);
    draw_score(game, win);
    for (int i = 0; i < 8; i++) {
        pause_buttons(win, defender, game, i);
        sfRenderWindow_drawSprite(win, defender->p_menu.pause_b[i].sprite, NULL);
    }
    game->bloon = game->head;
}
