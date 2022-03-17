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
    int leave = sfFloatRect_contains(&rectleave, d->cursor.pos.x, d->cursor.pos.y);
    if (leave == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->htp_leave.rect.left = 3194 + 560;
    else if (leave == 1)
        d->htp_leave.rect.left = 3194 + 280;
    else
        d->htp_leave.rect.left = 3194;
}

void switch_window_2(sfRenderWindow *window, defender_t *defender)
{
    if (defender->event.mouseButton.type == sfEvtMouseButtonReleased
    && defender->event.mouseButton.button == sfMouseLeft) {
        if (defender->valid[0]) {
            sfMusic_stop(defender->menu_music);
            defender->scene = GAME;
        }
        if (defender->valid[1]) {
            defender->scene = SETTINGS;
        }
        if (defender->valid[2]) {
            defender->scene = HOW_TO_PLAY;
        }
        if (defender->valid[3]) {
            sfRenderWindow_close(window);
        }
    }
}

void how_to_play(sfRenderWindow *win, defender_t *defender)
{
    if (sfMusic_getStatus(defender->menu_music) == 0)
        sfMusic_play(defender->menu_music);
    display_go(win, defender->menu);
    display_rect_hb(win, defender->htpback);
    sfRenderWindow_drawText(win, defender->help_txt, NULL);
    display_go(win, defender->htp_leave);
    sfFloatRect recthtp_leave = sfSprite_getGlobalBounds(defender->htp_leave.sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        defender->settings_click = 1;
    if (sfFloatRect_contains(&recthtp_leave, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        defender->settings_click = 0;
        defender->scene = MENU;
    }
    change_bouton_leave_htp(win, defender);
}
