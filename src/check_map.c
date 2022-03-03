/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "my_defender.h"

void check_pos(game_t *game, sfRenderWindow *window)
{
    unsigned long long int coords = ((roundf(game->bloon->pos.x) +
    (game->bloon->dir.x * - 1) * 50) * 4) + ((roundf(game->bloon->pos.y) +
    (game->bloon->dir.y * - 1) * 50) * 4 * 1920);
    if (coords >= 0 && coords <= 2147483647) {
        sfVector3f color = (sfVector3f) {game->pixels[coords],
        game->pixels[coords + 1], game->pixels[coords + 2]};
        if (color.x == game->colors[4].x && color.y ==
            game->colors[4].y && color.z == game->colors[4].z) {
            delete_bloon(game);
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (color.x == game->colors[i].x && color.y ==
                game->colors[i].y && color.z == game->colors[i].z) {
                game->bloon->dir = game->dirs[i];
            }
        }
    }
}
