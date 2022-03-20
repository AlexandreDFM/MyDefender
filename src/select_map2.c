/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** select_map2
*/

#include "my_defender.h"

void easy_medium(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box1 = (sfFloatRect) {314, 783, 57, 56};
    sfFloatRect box2 = (sfFloatRect) {314 + 57 + 372, 783, 57, 56};
    if (sfFloatRect_contains(&box1, def->cursor.pos.x,
    def->cursor.pos.y) && def->event.type == sfEvtMouseButtonReleased
    && def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_click == 1) {
            def->map_select_d.pos = (sfVector2f) {314, 783};
            def->difficulty = EASY;
            def->settings_click = 0;
        }
    }
    if (sfFloatRect_contains(&box2, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_click == 1) {
            def->map_select_d.pos = (sfVector2f) {314 + 57 + 372, 783};
            def->difficulty = MEDIUM;
            def->settings_click = 0;
        }
    }
}

void click_difficulty(sfRenderWindow *win, defender_t *def)
{
    easy_medium(win, def);
    sfFloatRect box3 = (sfFloatRect) {314 + 57 + 372 + 57 + 465, 783, 57, 56};
    if (sfFloatRect_contains(&box3, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_click == 1) {
            def->map_select_d.pos = (sfVector2f) {1265, 783};
            def->difficulty = HARD;
            def->settings_click = 0;
        }
    }
}

void general_display(sfRenderWindow *w, defender_t *def, game_t *game)
{
    if (sfMusic_getStatus(def->m_music) == 0)
        sfMusic_play(def->m_music);
    display_go(w, def->menu);
    display_go(w, def->map_select_b);
    display_go(w, def->map_select_l);
    for (int i = 0; i < 4; i++)
        display_go(w, def->map_select_m[i]);
    display_go(w, def->map_select_bl);
    display_go(w, def->map_select_br);
    display_go(w, def->map_select_d);
    display_bouton(w, def->map_select_go);
    sfFloatRect rmsel_l = sfSprite_getGlobalBounds(def->map_select_l.sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) def->settings_click = 1;
    if (sfFloatRect_contains(&rmsel_l, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft && def->settings_click == 1) {
        def->settings_click = 0;
        def->scene = MENU;
    }
}

void select_map(sfRenderWindow *w, defender_t *def, game_t *game)
{
    general_display(w, def, game);
    sfFloatRect rmsel_go = sfSprite_getGlobalBounds(def->map_select_go.sprite);
    change_bouton_lr(w, def);
    change_bouton_go(w, def);
    change_bouton_leave_sm(w, def);
    click_difficulty(w, def);
    if (sfFloatRect_contains(&rmsel_go, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        def->settings_click = 0;
        sfMusic_stop(def->m_music);
        init_textures(def, game);
        def->scene = GAME;
    }
    if (def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft)
        change_map(w, def);
}
