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
    cursor.s_monkey = NO_MONKEY;
    cursor.monkey = c_monkey(pos, (sfIntRect) {0, 0, 111, 114}, (sfVector2f) {0.75, 0.75}, DART_MONKEY);
    cursor.monkey_c = c_monkey_c(pos, 100, (sfVector2f) {0.75, 0.75}, sfRed);
    cursor.pos = pos;
    cursor.rect = rect;
    cursor.resize = (sfVector2f) {1, 1};
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfTrue);
    sfSprite_setPosition(cursor.sprite, cursor.pos);
    sfSprite_setScale(cursor.sprite, cursor.resize);
    sfSprite_setTextureRect(cursor.sprite, cursor.rect);
    return cursor;
}

void display_cursor(sfRenderWindow *window, game_t *game, defender_t *defender, cursor_t cursor)
{
    cursor.pos.x = (float) sfMouse_getPositionRenderWindow(window).x;
    cursor.pos.y = (float) sfMouse_getPositionRenderWindow(window).y;
    cursor.monkey.pos.x = cursor.pos.x;
    cursor.monkey.pos.y = cursor.pos.y;
    cursor.monkey_c.pos.x = cursor.pos.x;
    cursor.monkey_c.pos.y = cursor.pos.y;
    if (cursor.s_monkey != NO_MONKEY) {
        if (check_m_pos(game, defender)) {
            cursor.monkey_c.color = (sfColor) {0, 255, 0, 120};
        } else {
            cursor.monkey_c.color = (sfColor) {255, 0, 0, 120};
        }
        display_monkey_hb(window, cursor.monkey_c);
        display_monkey(window, cursor.monkey);
    }
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
