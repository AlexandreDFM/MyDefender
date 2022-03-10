/*
** EPITECH PROJECT, 2022
** monkey
** File description:
** Functions about monkeys
*/

#include "my_defender.h"

void fill_r_to(game_t *game)
{
    char **temp_rect = NULL;
    int size_array = 0;
    for (int i = 1; game->tower_stats[i] != NULL; i += 8, size_array++);
    sfIntRect *r_to = malloc(sizeof(sfIntRect) * size_array);
    for (int i = 0, j = 1; i < size_array - 1; j += 9, i++) {
        temp_rect = my_strtwa(game->tower_stats[j], "|");
        r_to[i] = (sfIntRect) {my_atoi(temp_rect[1]),
        my_atoi(temp_rect[2]), my_atoi(temp_rect[3]), my_atoi(temp_rect[4])};
        temp_rect = NULL;
    }
    free(temp_rect);
    game->r_to = r_to;
}

int tower(int mode)
{
    switch (mode) {
        case DART_MONKEY :
            return 0;
        case TACK_SHOOTER :
            return 1;
        case NINJA_MONKEY :
            return 2;
        case BOMB_SHOOTER :
            return 3;
        case ICE_MONKEY :
            return 4;
        case GLUE_GUNNER :
            return 5;
        case SUPER_MONKEY :
            return 6;
    };
    return 84;
}

void check_thud_hb(sfRenderWindow *w, game_t *g, defender_t *d)
{
    for (int y = 0, monkey = 1; y < 7; y++) {
        for (int x = 0; x < 2; x++, monkey++) {
            if (sfFloatRect_contains(&g->tower_box[y][x],
            d->cursor.pos.x, d->cursor.pos.y) &&
            d->event.mouseButton.type == sfEvtMouseButtonReleased
            && d->event.mouseButton.button == sfMouseLeft) {
                if (tower(monkey) != 84) {
                    d->cursor.t_to = monkey;
                    d->cursor.monkey.hitbox = g->r_to[tower(monkey)];
                }
            } else if (d->cursor.t_to > NO_MONKEY &&
            d->event.mouseButton.type == sfEvtMouseButtonPressed &&
            d->event.mouseButton.button == sfMouseLeft) {
                if (check_t_pl(g, d)) tower_node(w, g, d);
                d->cursor.t_to = NO_MONKEY;
            }
        }
    }
}
