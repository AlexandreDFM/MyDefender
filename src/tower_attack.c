/*
** EPITECH PROJECT, 2022
** tower_attack
** File description:
** Function to manage towers attack
*/

#include "my_defender.h"

void check_tower_radius(game_t *game, defender_t *defender)
{
    while (defender->playing == 1 && game->monkey != NULL) {
        while (game->bloon != NULL && game->bloon->next != NULL && defender->playing == 1) {
            if ((game->bloon->pos.x + game->monkey->radius / 2 >= game->monkey->pos.x - game->monkey->radius / 2
            && game->bloon->pos.x - game->monkey->radius / 2 <= game->monkey->pos.x + game->monkey->radius / 2)
            && (game->bloon->pos.y + game->monkey->radius / 2 >= game->monkey->pos.y - game->monkey->radius / 2
            && game->bloon->pos.y - game->monkey->radius / 2 <= game->monkey->pos.y + game->monkey->radius / 2)) {
                if (game->monkey->blooncibled == NULL) {
                    game->monkey->blooncibled = game->bloon;
                    //printf("I'm Monkey at %f %f and I have a ballon in my radius (%d) at %f %f\n", game->monkey->pos.x, game->monkey->pos.y, game->monkey->radius, game->bloon->pos.x, game->bloon->pos.y);
                }
            };
            game->bloon = game->bloon->next;
        }
        game->bloon = game->head;
        game->monkey = game->monkey->next;
    }
    game->monkey = game->monkey_head;
}

void change_enemies_rank(game_t *game, defender_t *defender)
{
    if (game->monkey->blooncibled->health == 1)
        red_bloons(game->monkey->blooncibled);
    if (game->monkey->blooncibled->health == 2)
        blue_bloons(game->monkey->blooncibled);
    if (game->monkey->blooncibled->health == 3)
        green_bloons(game->monkey->blooncibled);
    if (game->monkey->blooncibled->health == 4)
        yellow_bloons(game->monkey->blooncibled);
}

void tower_launch_attack(game_t *game, defender_t *defender)
{
    while (defender->playing == 1 && game->monkey != NULL) {
        if (game->monkey->blooncibled != NULL) {
            //printf("%f\n", atan2f(game->monkey->blooncibled->pos.y - game->monkey->pos.y, game->monkey->blooncibled->pos.x - game->monkey->pos.x) * 360.0 / 3.14 - 180);
            sfSprite_setRotation(game->monkey->sprite, atan2f(game->monkey->blooncibled->pos.y - game->monkey->pos.y, game->monkey->blooncibled->pos.x - game->monkey->pos.x) * 360.0 / 3.14 - 180);
        }
        //printf("%lld\n", sfClock_getElapsedTime(game->monkey->clockattack).microseconds);
        if (game->monkey->blooncibled != NULL && sfClock_getElapsedTime(game->monkey->clockattack).microseconds > (6000000 / game->monkey->attackspeed)) {
            game->monkey->blooncibled->health -= game->monkey->damage;
            sfSound_play(defender->pop[rand() % 4]);
            sfClock_restart(game->monkey->clockattack);
        }
        if (game->monkey->blooncibled != NULL)
            change_enemies_rank(game, defender);
        if (game->monkey->blooncibled != NULL && game->monkey->blooncibled->health <= 0) {
            game->monkey->blooncibled = NULL;
        }
        game->monkey = game->monkey->next;
    }
    game->monkey = game->monkey_head;
}

void bloons_check_is_life(game_t *game, defender_t *defender)
{
    while (defender->playing == 1 && game->bloon != NULL && game->bloon->next != NULL) {
        if (game->bloon->health <= 0) {
            delete_bloon(game);
        }
        game->bloon = game->bloon->next;
    }
    game->bloon = game->head;
}

void tower_attack(game_t *game, defender_t *defender)
{
    check_tower_radius(game, defender);
    tower_launch_attack(game, defender);
    bloons_check_is_life(game, defender);
}
