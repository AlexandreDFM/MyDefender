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
    sfRenderWindow_drawSprite(win, game_s->bloon.sprite, NULL);
    sfRenderWindow_drawSprite(win, game_s->hud, NULL);
    sfSprite_setPosition(game_s->bloon.sprite, game_s->bloon.pos);
    game_s->bloon.pos.x += game_s->bloon.dir.x;
    game_s->bloon.pos.y += game_s->bloon.dir.y;
    check_pos(game_s, win);
}
