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
