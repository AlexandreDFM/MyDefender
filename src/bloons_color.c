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
    obj->health = 2;
    obj->speed = 1.f;
    obj->damage = 2;
}

void green_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {84, 0, 42, 54});
    obj->type = GREEN;
    obj->health = 3;
    obj->speed = 1.5f;
    obj->damage = 3;
}

void yellow_bloons(bloons_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {126, 0, 42, 54});
    obj->type = YELLOW;
    obj->health = 4;
    obj->speed = 2.f;
    obj->damage = 4;
}
