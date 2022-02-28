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

void game(sfRenderWindow *win, game_t *game_s)
{
    sfRenderWindow_drawSprite(win, game_s->map, NULL);
    while (game_s->bloon != NULL && game_s->bloon->next != NULL) {
        if (sfFloatRect_contains(&game_s->frame, game_s->bloon->pos.x, game_s->bloon->pos.y)){
            sfRenderWindow_drawSprite(win, game_s->bloon->sprite, NULL);
            sfSprite_setPosition(game_s->bloon->sprite, game_s->bloon->pos);
            check_pos(game_s, win);
        }
        game_s->bloon->pos.x += game_s->bloon->dir.x * game_s->bloon->speed;
        game_s->bloon->pos.y += game_s->bloon->dir.y * game_s->bloon->speed;;
        game_s->bloon = game_s->bloon->next;
    }
    sfRenderWindow_drawSprite(win, game_s->hud, NULL);
    draw_score(game_s, win);
    game_s->bloon = game_s->head;
}
