/*
** EPITECH PROJECT, 2022
** how_to_play
** File description:
** Function to display the how to play
*/

#include "my_defender.h"

void change_bouton_leave_htp(sfRenderWindow *w, defender_t *d)
{
    sfFloatRect rectleave = sfSprite_getGlobalBounds(d->htp_leave.sprite);
    int l = sfFloatRect_contains(&rectleave, d->cursor.pos.x, d->cursor.pos.y);
    if (l == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->htp_leave.rect.left = 3194 + 560;
    else if (l == 1)
        d->htp_leave.rect.left = 3194 + 280;
    else
        d->htp_leave.rect.left = 3194;
}

void switch_window_2(sfRenderWindow *window, defender_t *def)
{
    if (def->event.mouseButton.type == sfEvtMouseButtonReleased
    && def->event.mouseButton.button == sfMouseLeft) {
        if (def->valid[0]) {
            sfMusic_stop(def->m_music);
            def->scene = GAME;
        }
        if (def->valid[1]) {
            def->scene = SETTINGS;
        }
        if (def->valid[2]) {
            def->scene = HOW_TO_PLAY;
        }
        if (def->valid[3]) {
            sfRenderWindow_close(window);
        }
    }
}

void how_to_play(sfRenderWindow *win, defender_t *def)
{
    if (sfMusic_getStatus(def->m_music) == 0)
        sfMusic_play(def->m_music);
    display_go(win, def->menu);
    display_rect_hb(win, def->htpback);
    sfRenderWindow_drawText(win, def->help_txt, NULL);
    display_go(win, def->htp_leave);
    sfFloatRect recthtp_leave =
    sfSprite_getGlobalBounds(def->htp_leave.sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        def->settings_click = 1;
    if (sfFloatRect_contains(&recthtp_leave,
    def->cursor.pos.x, def->cursor.pos.y)
    && def->event.type == sfEvtMouseButtonReleased &&
    def->event.mouseButton.button == sfMouseLeft) {
        def->settings_click = 0;
        def->scene = MENU;
    }
    change_bouton_leave_htp(win, def);
}
