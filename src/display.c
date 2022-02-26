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
