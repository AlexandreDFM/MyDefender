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
    monkey.texture = sfTexture_createFromFile("sprites/all_monkey.png", NULL);
    monkey.pos = pos;
    monkey.hitbox = hitbox;
    monkey.resize = size;
    sfSprite_setTexture(monkey.sprite, monkey.texture, sfTrue);
    sfSprite_setPosition(monkey.sprite, monkey.pos);
    sfSprite_setOrigin(monkey.sprite, (sfVector2f)
    {monkey.hitbox.width / 2, monkey.hitbox.height / 2});
    sfSprite_setScale(monkey.sprite, monkey.resize);
    sfSprite_setTextureRect(monkey.sprite, monkey.hitbox);
    return monkey;
}

r_hb_t c_r_hitbox(sfVector2f pos, sfIntRect rect, sfVector2f size, sfColor c)
{
    r_hb_t r_hb;
    r_hb.shape = sfRectangleShape_create();
    r_hb.rect = rect;
    r_hb.color = c;
    r_hb.pos = pos;
    sfRectangleShape_setFillColor(r_hb.shape, r_hb.color);
    sfRectangleShape_setSize(r_hb.shape, (sfVector2f)
    {rect.width, rect.height});
    sfRectangleShape_setPosition(r_hb.shape, r_hb.pos);
    return r_hb;
}

c_hb_t c_c_hitbox(sfVector2f pos, float radius, sfVector2f size, sfColor c)
{
    c_hb_t c_hb;
    c_hb.shape = sfCircleShape_create();
    c_hb.radius = radius;
    c_hb.color = c;
    c_hb.pos = pos;
    sfCircleShape_setOutlineColor(c_hb.shape, (sfColor) {0, 0, 0, 30});
    sfCircleShape_setOutlineThickness(c_hb.shape, - (radius / 3));
    sfCircleShape_setFillColor(c_hb.shape, c_hb.color);
    sfCircleShape_setRadius(c_hb.shape, c_hb.radius);
    sfCircleShape_setPosition(c_hb.shape, c_hb.pos);
    return c_hb;
}
