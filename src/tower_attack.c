/*
** EPITECH PROJECT, 2022
** tower_attack
** File description:
** Function to manage towers attack
*/

#include "my_defender.h"

void agro(game_t *g, defender_t *defender)
{
    if ((g->bloon->pos.x + g->monkey->radius / 2
    >= g->monkey->pos.x - g->monkey->radius / 2
    && g->bloon->pos.x - g->monkey->radius / 2
    <= g->monkey->pos.x + g->monkey->radius / 2)
    && (g->bloon->pos.y + g->monkey->radius / 2
    >= g->monkey->pos.y - g->monkey->radius / 2
    && g->bloon->pos.y - g->monkey->radius / 2
    <= g->monkey->pos.y + g->monkey->radius / 2)) {
        if (g->monkey->blooncibled == NULL) {
            g->monkey->blooncibled = g->bloon;
        }
    };
}

void unagro(game_t *g, defender_t *defender)
{
    if (g->monkey->blooncibled == g->bloon) {
        if ((g->bloon->pos.x + g->monkey->radius / 2
        <= g->monkey->pos.x - g->monkey->radius / 2
        && g->bloon->pos.x - g->monkey->radius / 2
        >= g->monkey->pos.x + g->monkey->radius / 2)
        && (g->bloon->pos.y + g->monkey->radius / 2
        <= g->monkey->pos.y - g->monkey->radius / 2
        && g->bloon->pos.y - g->monkey->radius / 2
        >= g->monkey->pos.y + g->monkey->radius / 2)) {
            g->monkey->blooncibled = NULL;
        }
    }
}

void check_tower_radius(game_t *g, defender_t *defender)
{
    while (defender->playing == 1 && g->monkey != NULL) {
        while (g->bloon != NULL && g->bloon->next != NULL
        && defender->playing == 1) {
            agro(g, defender);
            unagro(g, defender);
            g->bloon = g->bloon->next;
        }
        g->bloon = g->head;
        g->monkey = g->monkey->next;
    }
    g->monkey = g->monkey_head;
}
