/*
** EPITECH PROJECT, 2022
** special_tower_nodes
** File description:
** Function for special towers
*/

#include "my_defender.h"

monkey_t *first_monkey(game_t *game, defender_t *defender, sfVector2f pos)
{
    monkey_t *obj = malloc(sizeof(monkey_t));
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->resize = (sfVector2f) {0.75, 0.75};
    add_icons(game, defender, obj);
    sfSprite_setTexture(obj->sprite, game->t_monkey, sfTrue);
    sfSprite_setTextureRect(obj->sprite,
    game->r_to[tower(defender->cursor.t_to)]);
    sfSprite_setScale(obj->sprite, obj->resize);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f)
    {game->r_to[tower(defender->cursor.t_to)].width / 2,
    game->r_to[tower(defender->cursor.t_to)].height / 2});
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}

void add_monkey(game_t *game, defender_t *defender, sfVector2f pos)
{
    monkey_t *obj = malloc(sizeof(monkey_t));
    monkey_t *last = game->monkey;
    while (last->next != NULL) last = last->next;
    obj->prev = last;
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->resize = (sfVector2f) {0.75, 0.75};
    add_icons(game, defender, obj);
    sfSprite_setScale(obj->sprite, obj->resize);
    sfSprite_setTexture(obj->sprite, game->t_monkey, sfTrue);
    sfSprite_setTextureRect(obj->sprite,
    game->r_to[tower(defender->cursor.t_to)]);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f)
    {game->r_to[tower(defender->cursor.t_to)].width / 2,
    game->r_to[tower(defender->cursor.t_to)].height / 2});
    obj->next = NULL;
    last->next = obj;
}
