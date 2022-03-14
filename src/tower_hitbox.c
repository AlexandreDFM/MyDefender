/*
** EPITECH PROJECT, 2022
** tower_hitbox
** File description:
** Function to make all towers hitboxes
*/

#include "my_defender.h"

void fill_recthudtowers(game_t *game)
{
    int x_first = 1508;
    int y_first = 200;
    sfFloatRect **tower_box = malloc(sizeof(sfFloatRect *) * 8);
    tower_box[7] = NULL;
    for (int i = 0; i < 7; i++) {
        tower_box[i] = malloc(sizeof(sfFloatRect) * 2);
        for (int j = 0; j < 2; j++, x_first += 88) {
            tower_box[i][j] = (sfFloatRect) {x_first, y_first,
            113 * 0.7017543859649123, 93 * 0.7017543859649123};
        }
        y_first += 87;
        x_first = 1508;
        if (i == 5)
            y_first += 81;
    }
    game->tower_box = tower_box;
}

void fill_hudtowers(game_t *g)
{
    fill_recthudtowers(g);
    for (int i = 0, nb = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++, nb++) {
            g->tower_hitbox[nb].shape = sfRectangleShape_create();
            g->tower_hitbox[nb].rect = (sfIntRect) {0, 0,
            (int) g->tower_box[i][j].width, (int) g->tower_box[i][j].height};
            g->tower_hitbox[nb].color = (sfColor) {255, 0, 0, 100};
            g->tower_hitbox[nb].pos =
            (sfVector2f) {g->tower_box[i][j].left, g->tower_box[i][j].top};
            sfRectangleShape_setFillColor(g->tower_hitbox[nb].shape,
            g->tower_hitbox[nb].color);
            sfRectangleShape_setSize(g->tower_hitbox[nb].shape, (sfVector2f)
            {g->tower_hitbox[nb].rect.width, g->tower_hitbox[nb].rect.height});
            sfRectangleShape_setPosition(g->tower_hitbox[nb].shape,
            g->tower_hitbox[nb].pos);
        }
    }
}
