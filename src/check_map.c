/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "my_defender.h"

game_t *check_pos(game_t *game, sfRenderWindow *window)
{
    unsigned long long int coords = game->bloon->pos.x * 4 + game->bloon->pos.y * 4 * 1920;
    sfVector3f color = (sfVector3f) {game->pixels[coords], game->pixels[coords + 1], game->pixels[coords + 2]};
    for (int i = 0; i < 4; i++) {
        if (color.x == game->colors[i].x && color.y == game->colors[i].y && color.z == game->colors[i].z) {
            game->bloon->dir = game->dirs[i];
        }
    }
}
