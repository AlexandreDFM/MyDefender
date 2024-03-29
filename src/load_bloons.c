/*
** EPITECH PROJECT, 2022
** load
** File description:
** load
*/

#include "my_defender.h"

void fill_bloons(game_t *game)
{
    bloons_t *obj = malloc(sizeof(bloons_t));
    bloons_t *last = game->bloon;
    while (last->next != NULL) last = last->next;
    obj->prev = last;
    obj->sprite = sfSprite_create();
    obj->pos = (sfVector2f) {last->pos.x - 30 * last->dir.x,
    last->pos.y - 30 * last->dir.y};
    sfSprite_setTexture(obj->sprite, game->t_array[2], sfTrue);
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {21, 27});
    obj->dir = game->bloon->dir;
    obj->next = NULL;
    last->next = obj;
}

bloons_t *load_bloons(defender_t *defender, game_t *game)
{
    bloons_t *obj = malloc(sizeof(bloons_t));
    char **positions = NULL;
    if (defender->map_select == 1)
        positions = my_strtwa(get_lines("maps/map1"), ":\n");
    else if (defender->map_select == 2)
        positions = my_strtwa(get_lines("maps/map2"), ":\n");
    else
        positions = my_strtwa(get_lines("maps/map3"), ":\n");
    obj->sprite = sfSprite_create();
    obj->pos = (sfVector2f) {my_atoi(positions[1]), my_atoi(positions[2])};
    sfSprite_setTexture(obj->sprite, game->t_array[2], sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {21, 27});
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 42, 54});
    obj->dir = (sfVector2f) {my_atoi(positions[7]), my_atoi(positions[8])};
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}

void delete_bloon(game_t *game)
{
    if (game->bloon == NULL) return;
    if (game->bloon == game->head)
        game->head = game->bloon->next;
    if (game->bloon->next != NULL)
        game->bloon->next->prev = game->bloon->prev;
    if (game->bloon->prev != NULL)
        game->bloon->prev->next = game->bloon->next;
    game->bloon = game->bloon->next;
}
