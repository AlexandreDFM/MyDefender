/*
** EPITECH PROJECT, 2022
** create
** File description:
** Function to create objects
*/

#include "my_defender.h"

intro_t create_intro(char *tpath, sfVector2f pos, sfIntRect rect)
{
    intro_t intro;
    intro.sprite = sfSprite_create();
    intro.texture = sfTexture_createFromFile(tpath, NULL);
    intro.pos = pos;
    intro.rect = rect;
    intro.resize = (sfVector2f) {5, 5};
    sfSprite_setTexture(intro.sprite, intro.texture, sfTrue);
    sfSprite_setPosition(intro.sprite, intro.pos);
    sfSprite_setScale(intro.sprite, intro.resize);
    sfSprite_setTextureRect(intro.sprite, intro.rect);
    return intro;
}

title_t create_title(char *tpath, sfVector2f pos, sfIntRect rect)
{
    title_t title;
    title.sprite = sfSprite_create();
    title.texture = sfTexture_createFromFile(tpath, NULL);
    title.pos = pos;
    title.rect = rect;
    title.resize = (sfVector2f) {0.5, 0.5};
    sfSprite_setTexture(title.sprite, title.texture, sfTrue);
    sfSprite_setPosition(title.sprite, title.pos);
    sfSprite_setScale(title.sprite, title.resize);
    sfSprite_setTextureRect(title.sprite, title.rect);
    return title;
}

menu_t create_menu(char *tpath, sfVector2f pos, sfIntRect rect)
{
    menu_t menu;
    menu.sprite = sfSprite_create();
    menu.texture = sfTexture_createFromFile(tpath, NULL);
    menu.pos = pos;
    menu.rect = rect;
    menu.resize = (sfVector2f) {2.9, 2.9};
    sfSprite_setTexture(menu.sprite, menu.texture, sfTrue);
    sfSprite_setPosition(menu.sprite, menu.pos);
    sfSprite_setScale(menu.sprite, menu.resize);
    sfSprite_setTextureRect(menu.sprite, menu.rect);
    return menu;
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
