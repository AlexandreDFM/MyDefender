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
    cursor.t_to = NO_MONKEY;
    cursor.monkey = c_monkey(pos, (sfIntRect) {0, 0, 111, 114},
    (sfVector2f) {0.75, 0.75}, DART_MONKEY);
    cursor.monkey_c = c_c_hitbox(pos, 100, (sfVector2f) {0.75, 0.75}, sfRed);
    cursor.pos = pos;
    cursor.rect = rect;
    cursor.resize = (sfVector2f) {1, 1};
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfTrue);
    sfSprite_setPosition(cursor.sprite, cursor.pos);
    sfSprite_setScale(cursor.sprite, cursor.resize);
    sfSprite_setTextureRect(cursor.sprite, cursor.rect);
    return cursor;
}

void d_cursor_2(sfRenderWindow *w, game_t *g, defender_t *d, cursor_t cur)
{
    if (cur.t_to > NO_MONKEY) {
        char **stats = my_strtwa(g->tower_stats[tower(cur.t_to) == 0 ?
        1 : tower(cur.t_to) * 9 + 1], "|");
        cur.monkey_c.radius = my_atoi(stats[5]);
        if (check_t_pl(g, d)) {
            cur.monkey_c.color = (sfColor) {0, 0, 0, 120};
        } else {
            cur.monkey_c.color = (sfColor) {255, 0, 0, 120};
        }
        display_circle_hb(w, cur.monkey_c);
        display_monkey(w, cur.monkey);
        free(stats);
    }
}

void d_cursor(sfRenderWindow *w, game_t *g, defender_t *d, cursor_t cur)
{
    cur.pos.x = (float) sfMouse_getPositionRenderWindow(w).x;
    cur.pos.y = (float) sfMouse_getPositionRenderWindow(w).y;
    cur.monkey.pos.x = cur.pos.x;
    cur.monkey.pos.y = cur.pos.y;
    cur.monkey_c.pos.x = cur.pos.x;
    cur.monkey_c.pos.y = cur.pos.y;
    d_cursor_2(w, g, d, cur);
    sfVector2f origin = {12, 12};
    if (sfMouse_isButtonPressed(sfMouseLeft))
        cur.rect = (sfIntRect) {0, 64, 64, 64};
    else
        cur.rect = (sfIntRect) {0, 0, 64, 64};
    sfSprite_setTexture(cur.sprite, cur.texture, sfTrue);
    sfSprite_setOrigin(cur.sprite, origin);
    sfSprite_setTextureRect(cur.sprite, cur.rect);
    sfSprite_setPosition(cur.sprite, cur.pos);
    sfRenderWindow_drawSprite(w, cur.sprite, NULL);
}
