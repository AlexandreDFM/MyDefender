/*
** EPITECH PROJECT, 2022
** check_tower_placement
** File description:
** Functions to check if a tower can be placed
*/

#include "my_defender.h"

int check_m(game_t *g, defender_t *d)
{
    int m = (d->cursor.pos.x * 4) + (d->cursor.pos.y * 7680);
    if (m <= 0 && m >= 2147483647) return 0;
    sfVector3f color_m = (sfVector3f) {g->pixels[m], g->pixels[m + 1],
    g->pixels[m + 2]};
    if (color_m.x != 0 || color_m.y != 0 || color_m.z != 0) return 0;
    return 1;
}

int check_aa(game_t *g, defender_t *d)
{
    int a1 = ((d->cursor.pos.x - g->r_to[tower(d->cursor.t_to)].width / 2 *
    16 / 100) * 4) + ((d->cursor.pos.y - g->r_to[tower(d->cursor.t_to)].height
    / 2) * 7680);
    int a2 = ((d->cursor.pos.x + g->r_to[tower(d->cursor.t_to)].width / 2 *
    16 / 100) * 4) + ((d->cursor.pos.y - g->r_to[tower(d->cursor.t_to)].height
    / 2) * 7680);
    if (a1 <= 0 && a1 >= 2147483647) return 0;
    if (a2 <= 0 && a2 >= 2147483647) return 0;
    sfVector3f color_a1 = (sfVector3f) {g->pixels[a1], g->pixels[a1 + 1],
    g->pixels[a1 + 2]};
    sfVector3f color_a2 = (sfVector3f) {g->pixels[a2], g->pixels[a2 + 1],
    g->pixels[a2 + 2]};
    if (color_a1.x != 0 || color_a1.y != 0 || color_a1.z != 0) return 0;
    if (color_a2.x != 0 || color_a2.y != 0 || color_a2.z != 0) return 0;
    return 1;
}

int check_bb(game_t *g, defender_t *d)
{
    int b1 = ((d->cursor.pos.x - g->r_to[tower(d->cursor.t_to)].width / 2 *
    16 / 100) * 4) + ((d->cursor.pos.y + g->r_to[tower(d->cursor.t_to)].height
    / 2 * 1 / 100) * 7680);
    int b2 = ((d->cursor.pos.x + g->r_to[tower(d->cursor.t_to)].width / 2 *
    16 / 100) * 4) + ((d->cursor.pos.y + g->r_to[tower(d->cursor.t_to)].height
    / 2 * 1 / 100) * 7680);
    if (b1 <= 0 && b1 >= 2147483647) return 0;
    if (b2 <= 0 && b2 >= 2147483647) return 0;
    sfVector3f color_b1 = (sfVector3f) {g->pixels[b1], g->pixels[b1 + 1],
    g->pixels[b1 + 2]};
    sfVector3f color_b2 = (sfVector3f) {g->pixels[b2], g->pixels[b2 + 1],
    g->pixels[b2 + 2]};
    if (color_b1.x != 0 || color_b1.y != 0 || color_b1.z != 0) return 0;
    if (color_b2.x != 0 || color_b2.y != 0 || color_b2.z != 0) return 0;
    return 1;
}

int check_on_tower(game_t *g, defender_t *d)
{
    if (g->monkey_head != NULL) {
        while (g->monkey != NULL) {
            sfFloatRect rect1 = sfSprite_getGlobalBounds(g->monkey->sprite);
            sfFloatRect rect2 = {(d->cursor.pos.x -
            g->r_to[tower(d->cursor.t_to)].width / 2 * 16 / 100),
            (d->cursor.pos.y - g->r_to[tower(d->cursor.t_to)].height / 2),
            g->r_to[tower(d->cursor.t_to)].width * 16 / 100,
            g->r_to[tower(d->cursor.t_to)].height * 99 / 100};
            if (sfFloatRect_intersects(&rect1, &rect2, NULL)) {
                g->monkey = g->monkey_head;
                return 0;
            }
            g->monkey = g->monkey->next;
        }
        g->monkey = g->monkey_head;
    }
    return 1;
}

int check_t_pl(game_t *g, defender_t *d)
{
    if (!check_m(g, d)) return 0;
    if (!check_aa(g, d)) return 0;
    if (!check_bb(g, d)) return 0;
    if (!check_on_tower(g, d)) return 0;
    return 1;
}
