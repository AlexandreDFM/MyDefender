/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** click_fps
*/

#include "my_defender.h"

void click_fps4(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box4 = (sfFloatRect) {1069, 560, 44, 47};
    if (sfFloatRect_contains(&box4, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_click == 1) {
            def->settings_c.pos = (sfVector2f) {1069, 560};
            def->fps = 0;
            sfRenderWindow_setFramerateLimit(win, def->fps);
            def->settings_click = 0;
        }
    }
}

void click_fps3(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box3 = (sfFloatRect) {939, 560, 44, 47};
    if (sfFloatRect_contains(&box3, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_click == 1) {
            def->settings_c.pos = (sfVector2f) {936, 560};
            def->fps = 120;
            sfRenderWindow_setFramerateLimit(win, def->fps);
            def->settings_click = 0;
        }
    }
    click_fps4(win, def);
}

void click_fps2(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box2 = (sfFloatRect) {669 + 35 + 44 + 78, 560, 44, 47};
    if (sfFloatRect_contains(&box2, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_click == 1) {
            def->settings_c.pos = (sfVector2f) {669 + 35 + 44 + 78, 560};
            def->fps = 60;
            sfRenderWindow_setFramerateLimit(win, def->fps);
            def->settings_click = 0;
        }
    }
    click_fps3(win, def);
}

void click_fps(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box1 = (sfFloatRect) {669 + 35, 560, 44, 47};
    if (sfFloatRect_contains(&box1, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_click == 1) {
            def->settings_c.pos = (sfVector2f) {669 + 35, 560};
            def->fps = 30;
            sfRenderWindow_setFramerateLimit(win, def->fps);
            def->settings_click = 0;
        }
    }
    click_fps2(win, def);
}
