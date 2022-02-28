/*
** EPITECH PROJECT, 2022
** bloons
** File description:
** bloons
*/

#include "my_defender.h"

void red_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 42, 54});
    obj->type = RED;
    obj->speed = 0.5f;
    obj->health = 1;
    obj->damage = 1;
}

void blue_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {42, 0, 42, 54});
    obj->type = BLUE;
    obj->speed = 1.f;
}

void green_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {84, 0, 42, 54});
    obj->type = GREEN;
    obj->speed = 1.5f;
}

void yellow_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {126, 0, 42, 54});
    obj->type = YELLOW;
    obj->speed = 2.f;
}
