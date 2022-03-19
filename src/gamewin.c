/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** gamewin
*/

#include "my_defender.h"

void switch_window_win(sfRenderWindow *w, defender_t *d, game_t *game)
{
    if (d->event.mouseButton.type == sfEvtMouseButtonReleased
    && d->event.mouseButton.button == sfMouseLeft) {
        if (d->valid[5]) {
            sfMusic_stop(d->menu_music);
            init_textures(d, game);
            d->scene = GAME;
        }
        if (d->valid[4]) {
            uninit_textures(d, game);
            d->scene = MENU;
        }
        if (d->valid[3]) {
            all_uninit(d, game);
            sfRenderWindow_close(w);
        }
    }
}

void game_win(sfRenderWindow *w, defender_t *defender, game_t *game)
{
    if (sfMusic_getStatus(defender->game_music) == 0)
        sfMusic_play(defender->game_music);
    sfRenderWindow_drawSprite(w, game->map, NULL);
    bloon_management(w, game, defender);
    sfRenderWindow_drawSprite(w, game->hud, NULL);
    sfRenderWindow_drawSprite(w, game->up_gui, NULL);
    sfRenderWindow_drawSprite(w, game->p_but[0].sprite, NULL);
    sfRenderWindow_drawSprite(w, game->p_but[1].sprite, NULL);
    if (game->health <= 0) game->health = 0;
    draw_score(w, game, defender);
    game->bloon = game->head;
    display_rect_hb(w, game->gameoverscreen);
    is_bouton(w, defender);
    switch_window_win(w, defender, game);
    display_bouton(w, defender->bouton[0]);
    display_bouton(w, defender->bouton[3]);
    display_bouton(w, defender->bouton[4]);
    display_bouton(w, defender->bouton[5]);
    sfRenderWindow_drawText(w, game->gamestate, NULL);
}
