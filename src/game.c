/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "my_defender.h"

void draw_score(game_t *game, sfRenderWindow *win)
{
    sfText_setString(game->sc, my_itoa(game->score));
    sfText_setString(game->h, my_itoa(game->health));
    sfRenderWindow_drawText(win, game->sc, NULL);
    sfRenderWindow_drawText(win, game->h, NULL);
}

void next_wave(game_t *game, sfRenderWindow *win, defender_t *defender)
{
    game->bloon->pos.y = -50;
    if (defender->aplay == 1) {
        fill_waves(game);
        defender->state = 1;
        defender->playing = 1;
    }else {
        game->p_but[0].rect.left = 0;
        sfSprite_setTextureRect(game->p_but[0].sprite, game->p_but[0].rect);
        defender->state = 4;
        defender->playing = 0;
    }

}

void game(sfRenderWindow *win, game_t *game_s, defender_t *defender)
{
    sfRenderWindow_drawSprite(win, game_s->map, NULL);
    while (game_s->bloon != NULL && game_s->bloon->next != NULL && defender->playing == 1) {
        if (sfFloatRect_contains(&game_s->frame, game_s->bloon->pos.x, game_s->bloon->pos.y)){
            sfRenderWindow_drawSprite(win, game_s->bloon->sprite, NULL);
            sfSprite_setPosition(game_s->bloon->sprite, game_s->bloon->pos);
            check_pos(game_s, win);
        }
        if (sfClock_getElapsedTime(game_s->c).microseconds > 40) {
            game_s->bloon->pos.x += game_s->bloon->dir.x * game_s->bloon->speed * game_s->ff;
            game_s->bloon->pos.y += game_s->bloon->dir.y * game_s->bloon->speed * game_s->ff;
            sfClock_restart(game_s->c);
            game_s->bloon = game_s->bloon->next;
        }
    }
    ig_but(game_s, defender, win);
    sfRenderWindow_drawSprite(win, game_s->hud, NULL);
    sfRenderWindow_drawSprite(win, game_s->up_gui, NULL);
    sfRenderWindow_drawSprite(win, game_s->p_but[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, game_s->p_but[1].sprite, NULL);
    draw_score(game_s, win);
    game_s->bloon = game_s->head;
    if (game_s->bloon == NULL || game_s->bloon->next == NULL) {
        next_wave(game_s, win, defender);
    }
}
