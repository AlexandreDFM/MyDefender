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
    obj->pos = (sfVector2f) { last->pos.x, last->pos.y - 30};
    sfSprite_setTexture(obj->sprite, game->t_array[2], sfTrue);
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {21, 27});
    // sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 42, 54});
    obj->dir = game->bloon->dir;
    obj->next = NULL;
    last->next = obj;
}

bloons_t *load_bloons(game_t *game)
{
    bloons_t *obj = malloc(sizeof(bloons_t));
    char **positions = my_str_to_word_array(get_lines("maps/map1"));
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
