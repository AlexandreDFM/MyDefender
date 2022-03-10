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

void reset(sfRenderWindow *win, defender_t *defender, game_t *game)
{
    while (game->bloon != NULL) {
        my_printf("NTM\n");
        delete_bloon(game);
        // sfSprite_setPosition(game->bloon, (sfVector2f) {0, 1600});
        // game->bloon = game->bloon->next;
    }
}

void check_but(sfRenderWindow *win, defender_t *defender, game_t *game, int i)
{
    switch (i) {
    case 0:
        defender->scene = GAME;
    case 1:
        break;
    case 2:
        // reset(win, defender, game);
        defender->scene = MENU;
    case 3:
        break;
    case 4: case 5: case 6:
        if (i == 4) defender->aplay = defender->aplay == 1 ? 0 : 1;
        defender->p_menu.pause_b[i].rect.left +=
        (defender->p_menu.pause_b[i].rect.left == 0 ||
        defender->p_menu.pause_b[i].rect.left == 252) ? 126 : -126;
    }
}

void pause_buttons(sfRenderWindow *win, defender_t *defender, game_t *game, int i)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    defender->cursor.pos.x = pos.x;
    defender->cursor.pos.y = pos.y;
    sfFloatRect rect =
    sfSprite_getGlobalBounds(defender->p_menu.pause_b[i].sprite);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        defender->p_menu.pause_b[i].clicked = 1;
        sfSprite_setScale(defender->p_menu.pause_b[i].sprite,
        (sfVector2f) {1.1, 1.1});
        if (sfMouse_isButtonPressed(sfMouseLeft) && defender->state == 0) {
            defender->state = 1;
            check_but(win, defender, game, i);
        }
    } else {
        defender->p_menu.pause_b[i].clicked = 0;
        sfSprite_setScale(defender->p_menu.pause_b[i].sprite,
        (sfVector2f) {1, 1});
    }
    if (defender->state != 0 && defender->event.type ==
        sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
            defender->state = 0;
    }
}

void pause_f(sfRenderWindow *win, defender_t *defender, game_t *game)
{
    p_draw(win, defender, game);
    sfRenderWindow_drawRectangleShape(win, defender->p_menu.fade, NULL);
    draw_score(game, win);
    for (int i = 0; i < 8; i++) {
        pause_buttons(win, defender, game, i);
        sfSprite_setTextureRect(defender->p_menu.pause_b[i].sprite, defender->p_menu.pause_b[i].rect);
        sfRenderWindow_drawSprite(win, defender->p_menu.pause_b[i].sprite, NULL);
    }
    game->bloon = game->head;
}
