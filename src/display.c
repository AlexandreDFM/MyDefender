/*
** EPITECH PROJECT, 2022
** display
** File description:
** Function to display object
*/

#include "my_defender.h"

void display_intro(sfRenderWindow *window, intro_t intro)
{
    sfSprite_setTexture(intro.sprite, intro.texture, sfTrue);
    sfSprite_setPosition(intro.sprite, intro.pos);
    sfSprite_setTextureRect(intro.sprite, intro.rect);
    sfSprite_setScale(intro.sprite, intro.resize);
    sfRenderWindow_drawSprite(window, intro.sprite, NULL);
}

void display_title(sfRenderWindow *window, title_t title)
{
    sfSprite_setTexture(title.sprite, title.texture, sfTrue);
    sfSprite_setPosition(title.sprite, title.pos);
    sfSprite_setTextureRect(title.sprite, title.rect);
    sfSprite_setScale(title.sprite, title.resize);
    sfRenderWindow_drawSprite(window, title.sprite, NULL);
}

void display_menu(sfRenderWindow *window, menu_t menu)
{
    sfSprite_setTexture(menu.sprite, menu.texture, sfTrue);
    sfSprite_setPosition(menu.sprite, menu.pos);
    sfSprite_setTextureRect(menu.sprite, menu.rect);
    sfSprite_setScale(menu.sprite, menu.resize);
    sfRenderWindow_drawSprite(window, menu.sprite, NULL);
}

void display_bouton(sfRenderWindow *window, bouton_t bouton)
{
    sfSprite_setTexture(bouton.sprite, bouton.texture, sfTrue);
    sfSprite_setPosition(bouton.sprite, bouton.pos);
    sfSprite_setTextureRect(bouton.sprite, bouton.rect);
    sfSprite_setScale(bouton.sprite, bouton.resize);
    sfRenderWindow_drawSprite(window, bouton.sprite, NULL);
}
