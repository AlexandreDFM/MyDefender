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
    int leave = sfFloatRect_contains(&rectleave, d->cursor.pos.x, d->cursor.pos.y);
    if (leave == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->settings_l.rect.left = 3194 + 560;
    else if (leave == 1)
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

void bar_volume(sfRenderWindow *win, defender_t *defender)
{
    sfFloatRect rectlarrow = (sfFloatRect) {707, 393, 50, 62};
    sfFloatRect rectrarrow = (sfFloatRect) {1167, 392, 50, 62};
    if (sfFloatRect_contains(&rectlarrow, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->settings_bar.rect.width > 0 && defender->settings_click == 1) {
            change_volume(win, defender, -10);
            defender->settings_bar.rect.width -= 51;
            defender->settings_click = 0;
        }
    }
    if (sfFloatRect_contains(&rectrarrow, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->settings_bar.rect.width < 510 && defender->settings_click == 1) {
            change_volume(win, defender, +10);
            defender->settings_bar.rect.width += 51;
            defender->settings_click = 0;
        }
    }
}

void click_fps2(sfRenderWindow *win, defender_t *defender)
{
    sfFloatRect box3 = (sfFloatRect) {669 + 35 + 44 + 78 + 35 + 78, 560, 44, 47};
    sfFloatRect box4 = (sfFloatRect) {669 + 35 + 44 + 78 + 35 + 78 + 44 + 86, 560, 44, 47};
    if (sfFloatRect_contains(&box3, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->settings_click == 1) {
            defender->settings_c.pos = (sfVector2f) {669 + 35 + 44 + 78 + 35 + 75, 560};
            defender->fps = 120;
            sfRenderWindow_setFramerateLimit(win, defender->fps);
            defender->settings_click = 0;
        }
    }
    if (sfFloatRect_contains(&box4, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->settings_click == 1) {
            defender->settings_c.pos = (sfVector2f) {669 + 35 + 44 + 78 + 35 + 78 + 44 + 86, 560};
            defender->fps = 0;
            sfRenderWindow_setFramerateLimit(win, defender->fps);
            defender->settings_click = 0;
        }
    }
}

void click_fps(sfRenderWindow *win, defender_t *defender)
{
    sfFloatRect box1 = (sfFloatRect) {669 + 35, 560, 44, 47};
    sfFloatRect box2 = (sfFloatRect) {669 + 35 + 44 + 78, 560, 44, 47};
    if (sfFloatRect_contains(&box1, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->settings_click == 1) {
            defender->settings_c.pos = (sfVector2f) {669 + 35, 560};
            defender->fps = 30;
            sfRenderWindow_setFramerateLimit(win, defender->fps);
            defender->settings_click = 0;
        }
    }
    if (sfFloatRect_contains(&box2, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->settings_click == 1) {
            defender->settings_c.pos = (sfVector2f) {669 + 35 + 44 + 78, 560};
            defender->fps = 60;
            sfRenderWindow_setFramerateLimit(win, defender->fps);
            defender->settings_click = 0;
        }
    }
    click_fps2(win, defender);
}

void settings(sfRenderWindow *win, defender_t *defender)
{
    if (sfMusic_getStatus(defender->menu_music) == 0)
        sfMusic_play(defender->menu_music);
    display_go(win, defender->menu);
    display_go(win, defender->settings_b);
    display_rect_hb(win, defender->settings_bar);
    display_go(win, defender->settings);
    display_go(win, defender->settings_c);
    display_go(win, defender->settings_l);
    sfFloatRect rectsettings_l = sfSprite_getGlobalBounds(defender->settings_l.sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        defender->settings_click = 1;
    if (sfFloatRect_contains(&rectsettings_l, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        defender->settings_click = 0;
        defender->scene = MENU;
    }
    change_bouton_leave_set(win, defender);
    click_fps(win, defender);
    bar_volume(win, defender);
}
