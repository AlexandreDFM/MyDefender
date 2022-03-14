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
    && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->valid[0]) {
            sfMusic_stop(defender->menu_music);
            defender->scene = GAME;
        }
        if (defender->valid[2]) {
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

void menu(sfRenderWindow *window, defender_t *defender)
{
    if (sfMusic_getStatus(defender->menu_music) == 0)
        sfMusic_play(defender->menu_music);
    display_go(window, defender->menu);
    display_go(window, defender->title);
    is_bouton(window, defender);
    switch_window(window, defender);
    for (int i = 0; i < 4; i++)
        display_bouton(window, defender->bouton[i]);
}

void ig_but(game_t *game, defender_t *defender, sfRenderWindow *win)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    defender->cursor.pos.x = pos.x;
    defender->cursor.pos.y = pos.y;
    for (int i = 0; i < 2; i++) {
        sfFloatRect rect = sfSprite_getGlobalBounds(game->p_but[i].sprite);
        if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
            game->p_but[i].clicked = 1;
            sfSprite_setScale(game->p_but[i].sprite, (sfVector2f) {0.6, 0.6});
        } else {
            game->p_but[i].clicked = 0;
            sfSprite_setScale(game->p_but[i].sprite, (sfVector2f) {0.5, 0.5});
        }
        if (game->p_but[i].clicked == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) &&
        defender->playing == 0 && i == 0) {
            if (defender->state == 4) fill_waves(game);
            defender->state = 1;
            defender->playing = 1;
            game->p_but[i].rect.left = (game->ff == 1) ? 126 : 252;
            sfSprite_setTextureRect(game->p_but[i].sprite, game->p_but[i].rect);
        }
        if (game->p_but[i].clicked == 1 && sfMouse_isButtonPressed(sfMouseLeft)
        && defender->playing == 1 && defender->state == 0 && i == 0) {
            defender->state = 3;
        }
        if (game->p_but[i].clicked == 1 && sfMouse_isButtonPressed(sfMouseLeft)
        && defender->state == 0 && i == 1) {
            defender->scene = PAUSE;
        }
        if (defender->state != 0 && defender->event.type ==
        sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
            if (defender->state == 3) {
                game->ff = (game->ff == 1 && defender->playing == 1) ? 2 : 1;
                game->p_but[i].rect.left = (game->p_but[i].rect.left == 126) ? 252 : 126;
                sfSprite_setTextureRect(game->p_but[i].sprite, game->p_but[i].rect);
            }
            defender->state = 0;
        }
    }
}
