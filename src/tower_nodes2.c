/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** tower_nodes2
*/

#include "my_defender.h"

void monkey_upgrade2(game_t *game, defender_t *defender, monkey_t *obj)
{
    sfRectangleShape_setFillColor(obj->hitbox_sell.shape,
    obj->hitbox_sell.color);
    sfRectangleShape_setSize(obj->hitbox_sell.shape,
    (sfVector2f) {obj->hitbox_sell.rect.width,
    obj->hitbox_sell.rect.height});
    sfRectangleShape_setPosition(obj->hitbox_sell.shape,
    obj->hitbox_sell.pos);
}

void monkey_upgrade(game_t *game, defender_t *defender, monkey_t *obj)
{
    obj->sell = sfText_create();
    sfText_setString(obj->sell, "SELL ALL !");
    sfText_setFont(obj->sell, game->font);
    sfText_setCharacterSize(obj->sell, 40);
    sfText_setPosition(obj->sell, (sfVector2f) {650, 905});
    obj->priority = sfText_create();
    sfText_setString(obj->priority, "PRIORITY");
    sfText_setFont(obj->priority, game->font);
    sfText_setCharacterSize(obj->priority, 40);
    sfText_setPosition(obj->priority, (sfVector2f) {540, 1010});
    obj->hitbox_sell.shape = sfRectangleShape_create();
    obj->hitbox_sell.rect = (sfIntRect) {0, 0, 165, 45};
    obj->hitbox_sell.color = (sfColor) {0, 0, 255, 100};
    obj->hitbox_sell.pos = (sfVector2f) {610, 910};
    monkey_upgrade2(game, defender, obj);
}
