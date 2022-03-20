/*
** EPITECH PROJECT, 2022
** bloons
** File description:
** bloons
*/

#include "my_defender.h"

void red_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 80, 107});
    sfSprite_setScale(obj->sprite, (sfVector2f) {0.505, 0.4846728972});
    obj->type = RED;
    obj->speed = 0.1f;
    obj->health = 1;
    obj->damage = 1;
    obj->clock = sfClock_create();
}

void blue_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {80, 0, 80, 107});
    sfSprite_setScale(obj->sprite, (sfVector2f) {0.505, 0.4846728972});
    obj->type = BLUE;
    obj->health = 2;
    obj->speed = 0.2f;
    obj->damage = 2;
    obj->clock = sfClock_create();
}

void green_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {160, 0, 80, 107});
    sfSprite_setScale(obj->sprite, (sfVector2f) {0.505, 0.4846728972});
    obj->type = GREEN;
    obj->health = 3;
    obj->speed = 0.4f;
    obj->damage = 3;
    obj->clock = sfClock_create();
}

void yellow_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {240, 0, 80, 107});
    sfSprite_setScale(obj->sprite, (sfVector2f) {0.505, 0.4846728972});
    obj->type = YELLOW;
    obj->health = 4;
    obj->speed = 0.8f;
    obj->damage = 4;
    obj->clock = sfClock_create();
}

void rainbow_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {320, 0, 80, 107});
    sfSprite_setScale(obj->sprite, (sfVector2f) {0.505, 0.4846728972});
    obj->type = RAINBOW;
    obj->health = 5;
    obj->speed = 1.6f;
    obj->damage = 5;
    obj->clock = sfClock_create();
}
