/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** change_volume
*/

#include "my_defender.h"

void change_volume(sfRenderWindow *win, defender_t *d, int offs)
{
    if ((d->volume_buf2 > 0 && offs < 0)
    || (d->volume_buf2 < 20 && offs > 0)) {
        d->volume_buf2 += (offs / 5);
        for (int i = 0; i < 4; i++)
            sfSound_setVolume(d->pop[i], d->volume_buf2);
    }
    if ((d->volume_buf > 0 && offs < 0) || (d->volume_buf < 50 && offs > 0)) {
        d->volume_buf += (offs / 2);
        sfSound_setVolume(d->slash, d->volume_buf);
        sfSound_setVolume(d->towertk, d->volume_buf);
        sfSound_setVolume(d->towerpl, d->volume_buf);
        sfSound_setVolume(d->towerdl, d->volume_buf);
    }
    if ((d->v_music > 0 && offs < 0) || (d->v_music < 100 && offs > 0)) {
        d->v_music += offs;
        sfMusic_setVolume(d->m_music, d->v_music);
        sfMusic_setVolume(d->g_music, d->v_music);
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
            def->settings_bar.rect.width += 51, def->settings_click = 0;
        }
    }
}
