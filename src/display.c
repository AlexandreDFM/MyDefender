/*
** EPITECH PROJECT, 2022
** display
** File description:
** Function to display object
*/

#include "my_defender.h"

void display_go(sfRenderWindow *w, go_t go)
{
    sfSprite_setTexture(go.sprite, go.texture, sfTrue);
    sfSprite_setPosition(go.sprite, go.pos);
    sfSprite_setTextureRect(go.sprite, go.rect);
    sfSprite_setScale(go.sprite, go.resize);
    sfRenderWindow_drawSprite(w, go.sprite, NULL);
}

void display_bouton(sfRenderWindow *window, bouton_t bouton)
{
    sfSprite_setTexture(bouton.sprite, bouton.texture, sfTrue);
    sfSprite_setPosition(bouton.sprite, bouton.pos);
    sfSprite_setTextureRect(bouton.sprite, bouton.rect);
    sfSprite_setScale(bouton.sprite, bouton.resize);
    sfRenderWindow_drawSprite(window, bouton.sprite, NULL);
}

void display_monkey(sfRenderWindow *w, monkey_t monkey)
{
    sfSprite_setTexture(monkey.sprite, monkey.texture, sfTrue);
    sfSprite_setPosition(monkey.sprite, monkey.pos);
    sfSprite_setTextureRect(monkey.sprite, monkey.hitbox);
    sfSprite_setOrigin(monkey.sprite, (sfVector2f)
    {monkey.hitbox.width / 2, monkey.hitbox.height / 2});
    sfSprite_setScale(monkey.sprite, monkey.resize);
    sfRenderWindow_drawSprite(w, monkey.sprite, NULL);
}

void display_monkey_hb(sfRenderWindow *w, c_hb_t hb_monkey)
{
    sfCircleShape_setFillColor(hb_monkey.shape, hb_monkey.color);
    sfCircleShape_setRadius(hb_monkey.shape, hb_monkey.radius);
    sfCircleShape_setPosition(hb_monkey.shape, hb_monkey.pos);
    sfCircleShape_setOrigin(hb_monkey.shape, (sfVector2f)
    {hb_monkey.radius, hb_monkey.radius});
    sfRenderWindow_drawCircleShape(w, hb_monkey.shape, NULL);
}
