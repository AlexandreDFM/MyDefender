/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "my_defender.h"

game_t *check_pos(game_t *game, sfRenderWindow *window)
{
    unsigned long long int coords = game->bloon.pos.x * 4 + game->bloon.pos.y * 4 * 1920;
    sfVector3f color = (sfVector3f) {game->pixels[coords], game->pixels[coords + 1], game->pixels[coords + 2]};
    if (color.x == 0 && color.y == 0 && color.z == 0) {
        my_printf("BLACK\n");
    }
    if (color.x == 255 && color.y == 255 && color.z == 255) {
        my_printf("WHITE\n");
    }
    if (color.x == 0 && color.y == 51 && color.z == 255) {
        my_printf("DOWN\n");
        game->bloon.dir = (sfVector2f) {0, 1};
    }
    if (color.x == 0 && color.y == 255 && color.z == 72) {
        my_printf("LEFT\n");
        game->bloon.dir = (sfVector2f) {-1, 0};
    }
    if (color.x == 197 && color.y == 0 && color.z == 0) {
        my_printf("RIGHT\n");
        game->bloon.dir = (sfVector2f) {1, 0};
    }
    if (color.x == 158 && color.y == 0 && color.z == 197) {
        my_printf("WHITE\n");
        game->bloon.dir = (sfVector2f) {0, -1};
    }
}
