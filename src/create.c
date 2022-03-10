/*
** EPITECH PROJECT, 2022
** create
** File description:
** Function to create objects
*/

#include "my_defender.h"

go_t create_go(char *tpath, sfVector2f pos, sfIntRect hitbox, sfVector2f size)
{
    go_t go;
    go.sprite = sfSprite_create();
    go.texture = sfTexture_createFromFile(tpath, NULL);
    go.pos = pos;
    go.rect = hitbox;
    go.resize = size;
    sfSprite_setTexture(go.sprite, go.texture, sfTrue);
    sfSprite_setPosition(go.sprite, go.pos);
    sfSprite_setScale(go.sprite, go.resize);
    sfSprite_setTextureRect(go.sprite, go.rect);
    return go;
}

bouton_t create_bouton(char *tpath, sfVector2f pos, sfIntRect rect)
{
    bouton_t bouton;
    bouton.sprite = sfSprite_create();
    bouton.texture = sfTexture_createFromFile(tpath, NULL);
    bouton.pos = pos;
    bouton.rect = rect;
    bouton.resize = (sfVector2f) {2, 2};
    sfSprite_setTexture(bouton.sprite, bouton.texture, sfTrue);
    sfSprite_setPosition(bouton.sprite, bouton.pos);
    sfSprite_setScale(bouton.sprite, bouton.resize);
    sfSprite_setTextureRect(bouton.sprite, bouton.rect);
    return bouton;
}

monkey_t c_monkey(sfVector2f pos, sfIntRect hitbox, sfVector2f size, int type)
{
    monkey_t monkey;
    monkey.sprite = sfSprite_create();
    monkey.texture = sfTexture_createFromFile("./sprites/all_monkey.png", NULL);
    monkey.pos = pos;
    monkey.hitbox = hitbox;
    monkey.resize = size;
    sfSprite_setTexture(monkey.sprite, monkey.texture, sfTrue);
    sfSprite_setPosition(monkey.sprite, monkey.pos);
    sfSprite_setOrigin(monkey.sprite, (sfVector2f) {monkey.hitbox.width / 2, monkey.hitbox.height / 2});
    sfSprite_setScale(monkey.sprite, monkey.resize);
    sfSprite_setTextureRect(monkey.sprite, monkey.hitbox);
    return monkey;
}

c_hb_t c_monkey_c(sfVector2f pos, float radius, sfVector2f size, sfColor color)
{
    c_hb_t monkey_c;
    monkey_c.shape = sfCircleShape_create();
    monkey_c.radius = radius;
    monkey_c.color = (sfColor) {255, 0, 0, 120};
    monkey_c.pos = pos;
    sfCircleShape_setOutlineColor(monkey_c.shape, (sfColor) {0, 0, 0, 30});
    sfCircleShape_setOutlineThickness(monkey_c.shape, - (radius / 3));
    sfCircleShape_setFillColor(monkey_c.shape, monkey_c.color);
    sfCircleShape_setRadius(monkey_c.shape, monkey_c.radius);
    sfCircleShape_setPosition(monkey_c.shape, monkey_c.pos);
    return monkey_c;
}
