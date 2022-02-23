/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "my_defender.h"

void game(sfRenderWindow *win, game_t *game_s)
{
    sfRenderWindow_drawSprite(win, game_s->map, NULL);
    sfRenderWindow_drawSprite(win, game_s->hud, NULL);
    while(game_s->bloon->next != NULL) {
        if (sfFloatRect_contains(&game_s->frame, game_s->bloon->pos.x, game_s->bloon->pos.y)){
            sfRenderWindow_drawSprite(win, game_s->bloon->sprite, NULL);
            sfSprite_setPosition(game_s->bloon->sprite, game_s->bloon->pos);
            check_pos(game_s, win);
        }
        game_s->bloon->pos.x += game_s->bloon->dir.x;
        game_s->bloon->pos.y += game_s->bloon->dir.y;
        game_s->bloon = game_s->bloon->next;
    }
    // usleep(5000);
    game_s->bloon = game_s->head;
}
