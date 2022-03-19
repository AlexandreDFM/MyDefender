/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** settings
*/

#include "my_defender.h"

void change_bouton_leave_set(sfRenderWindow *w, defender_t *d)
{
    sfFloatRect rectleave = sfSprite_getGlobalBounds(d->settings_l.sprite);
    int l = sfFloatRect_contains(&rectleave, d->cursor.pos.x, d->cursor.pos.y);
    if (l == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->settings_l.rect.left = 3194 + 560;
    else if (l == 1)
        d->settings_l.rect.left = 3194 + 280;
    else
        d->settings_l.rect.left = 3194;
}

void change_volume(sfRenderWindow *win, defender_t *d, int offset)
{
    if ((d->volume_buf2 > 0 && offset < 0) ||
    (d->volume_buf2 < 20 && offset > 0)) {
        d->volume_buf2 += (offset / 5);
        for (int i = 0; i < 4; i++)
            sfSound_setVolume(d->pop[i], d->volume_buf2);
    }
    if ((d->volume_buf > 0 && offset < 0) ||
    (d->volume_buf < 50 && offset > 0)) {
        d->volume_buf += (offset / 2);
        sfSound_setVolume(d->slash, d->volume_buf);
        sfSound_setVolume(d->towertk, d->volume_buf);
        sfSound_setVolume(d->towerpl, d->volume_buf);
        sfSound_setVolume(d->towerdl, d->volume_buf);
    }
    if ((d->volume_music > 0 && offset < 0) ||
    (d->volume_music < 100 && offset > 0)) {
        d->volume_music += offset;
        sfMusic_setVolume(d->menu_music, d->volume_music);
        sfMusic_setVolume(d->game_music, d->volume_music);
    }
}

void bar_volume(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect rlarrow = (sfFloatRect) {707, 393, 50, 62};
    sfFloatRect rrarrow = (sfFloatRect) {1167, 392, 50, 62};
    if (sfFloatRect_contains(&rlarrow, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_bar.rect.width > 0 && def->settings_click == 1) {
            change_volume(win, def, -10);
            def->settings_bar.rect.width -= 51;
            def->settings_click = 0;
        }
    }
    if (sfFloatRect_contains(&rrarrow, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        if (def->settings_bar.rect.width < 510 && def->settings_click == 1) {
            change_volume(win, def, +10);
            def->settings_bar.rect.width += 51;
            def->settings_click = 0;
        }
    }
}

void click_fps2(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box3 = (sfFloatRect) {939, 560, 44, 47};
    sfFloatRect box4 = (sfFloatRect) {1069, 560, 44, 47};
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

void click_fps(sfRenderWindow *win, defender_t *def)
{
    sfFloatRect box1 = (sfFloatRect) {669 + 35, 560, 44, 47};
    sfFloatRect box2 = (sfFloatRect) {669 + 35 + 44 + 78, 560, 44, 47};
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
    click_fps2(win, def);
}

void settings(sfRenderWindow *win, defender_t *def)
{
    if (sfMusic_getStatus(def->menu_music) == 0)
        sfMusic_play(def->menu_music);
    display_go(win, def->menu);
    display_go(win, def->settings_b);
    display_rect_hb(win, def->settings_bar);
    display_go(win, def->settings);
    display_go(win, def->settings_c);
    display_go(win, def->settings_l);
    sfFloatRect rs_l = sfSprite_getGlobalBounds(def->settings_l.sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        def->settings_click = 1;
    if (sfFloatRect_contains(&rs_l, def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        def->settings_click = 0;
        def->scene = MENU;
    }
    change_bouton_leave_set(win, def);
    click_fps(win, def);
    bar_volume(win, def);
}
