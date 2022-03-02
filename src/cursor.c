/*
** EPITECH PROJECT, 2022
** cursor
** File description:
** All fonctions about cursor
*/

#include "my_defender.h"

cursor_t create_cursor(char *tpath, sfVector2f pos, sfIntRect rect)
{
    cursor_t cursor;
    cursor.sprite = sfSprite_create();
    cursor.texture = sfTexture_createFromFile(tpath, NULL);
    cursor.pos = pos;
    cursor.rect = rect;
    cursor.resize = (sfVector2f) {1, 1};
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfTrue);
    sfSprite_setPosition(cursor.sprite, cursor.pos);
    sfSprite_setScale(cursor.sprite, cursor.resize);
    sfSprite_setTextureRect(cursor.sprite, cursor.rect);
    return cursor;
}

void display_cursor(sfRenderWindow *window, cursor_t cursor)
{
    cursor.pos.x = (float) sfMouse_getPositionRenderWindow(window).x;
    cursor.pos.y = (float) sfMouse_getPositionRenderWindow(window).y;
    sfVector2f origin = {12, 12};
    if (sfMouse_isButtonPressed(sfMouseLeft))
        cursor.rect = (sfIntRect) {0, 64, 64, 64};
    else
        cursor.rect = (sfIntRect) {0, 0, 64, 64};
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfTrue);
    sfSprite_setOrigin(cursor.sprite, origin);
    sfSprite_setTextureRect(cursor.sprite, cursor.rect);
    sfSprite_setPosition(cursor.sprite, cursor.pos);
    sfRenderWindow_drawSprite(window, cursor.sprite, NULL);
}
