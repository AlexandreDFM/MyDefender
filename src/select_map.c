/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** select_map
*/

#include "my_defender.h"

void change_bouton_go(sfRenderWindow *window, defender_t *defender)
{
    float posmousex = defender->cursor.pos.x;
    float posmousey = defender->cursor.pos.y;
    sfFloatRect b = {defender->map_select_go.pos.x,
    defender->map_select_go.pos.y,
    defender->map_select_go.rect.width * defender->map_select_go.resize.x,
    defender->map_select_go.rect.height * defender->map_select_go.resize.y};
    int in = sfFloatRect_contains(&b, posmousex, posmousey);
    if (in == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        defender->map_select_go.rect.left = 4576 + 318;
    else if (in == 1)
        defender->map_select_go.rect.left = 4576 + 159;
    else
        defender->map_select_go.rect.left = 4576;
}

void change_bouton_leave_sm(sfRenderWindow *w, defender_t *d)
{
    sfFloatRect rel = sfSprite_getGlobalBounds(d->map_select_l.sprite);
    int leave = sfFloatRect_contains(&rel, d->cursor.pos.x, d->cursor.pos.y);
    if (leave == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->map_select_l.rect.left = 3194 + 560;
    else if (leave == 1)
        d->map_select_l.rect.left = 3194 + 280;
    else
        d->map_select_l.rect.left = 3194;
}

void change_bouton_lr(sfRenderWindow *win, defender_t *d)
{
    sfFloatRect rectl = sfSprite_getGlobalBounds(d->map_select_bl.sprite);
    sfFloatRect rectr = sfSprite_getGlobalBounds(d->map_select_br.sprite);
    int l = sfFloatRect_contains(&rectl, d->cursor.pos.x, d->cursor.pos.y);
    if (l == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->map_select_bl.rect.left = 3053 + 560;
    else if (l == 1)
        d->map_select_bl.rect.left = 3053 + 280;
    else
        d->map_select_bl.rect.left = 3053;
    int r = sfFloatRect_contains(&rectr, d->cursor.pos.x, d->cursor.pos.y);
    if (r == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->map_select_br.rect.left = 3053 + 560;
    else if (r == 1)
        d->map_select_br.rect.left = 3053 + 280;
    else
        d->map_select_br.rect.left = 3053;
}

void change_map(sfRenderWindow *win, defender_t *d)
{
    sfFloatRect rectlarrow = sfSprite_getGlobalBounds(d->map_select_bl.sprite);
    sfFloatRect rectrarrow = sfSprite_getGlobalBounds(d->map_select_br.sprite);
    if (sfFloatRect_contains(&rectlarrow, d->cursor.pos.x, d->cursor.pos.y)) {
        if (d->map_select_m[3].pos.x > 215 && d->settings_click == 1) {
            d->map_select_m[3].pos.x -= 500;
            d->map_select -= 1;
            d->settings_click = 0;
        }
    }
    if (sfFloatRect_contains(&rectrarrow, d->cursor.pos.x, d->cursor.pos.y)) {
        if (d->map_select_m[3].pos.x < 1215 && d->settings_click == 1) {
            d->map_select_m[3].pos.x += 500;
            d->map_select += 1;
            d->settings_click = 0;
        }
    }
}

void click_difficulty(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box1 = (sfFloatRect) {314, 783, 57, 56};
    sfFloatRect box2 = (sfFloatRect) {314 + 57 + 372, 783, 57, 56};
    sfFloatRect box3 = (sfFloatRect) {314 + 57 + 372 + 57 + 465, 783, 57, 56};
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

void select_map(sfRenderWindow *w, defender_t *def, game_t *game)
{
    if (sfMusic_getStatus(def->menu_music) == 0)
        sfMusic_play(def->menu_music);
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
    sfFloatRect rmsel_go = sfSprite_getGlobalBounds(def->map_select_go.sprite);
    change_bouton_lr(w, def);
    change_bouton_go(w, def);
    change_bouton_leave_sm(w, def);
    click_difficulty(w, def);
    if (sfFloatRect_contains(&rmsel_go, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        def->settings_click = 0;
        sfMusic_stop(def->menu_music);
        init_textures(def, game);
        def->scene = GAME;
    }
    if (def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft)
        change_map(w, def);
}
