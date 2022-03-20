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

void settings(sfRenderWindow *win, defender_t *def)
{
    if (sfMusic_getStatus(def->m_music) == 0)
        sfMusic_play(def->m_music);
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
        def->settings_click = 0, def->scene = MENU;
    }
    change_bouton_leave_set(win, def);
    click_fps(win, def);
    bar_volume(win, def);
}
