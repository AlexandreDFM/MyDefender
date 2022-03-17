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
    sfFloatRect b = {defender->map_select_go.pos.x, defender->map_select_go.pos.y,
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
    sfFloatRect rectleave = sfSprite_getGlobalBounds(d->map_select_l.sprite);
    int leave = sfFloatRect_contains(&rectleave, d->cursor.pos.x, d->cursor.pos.y);
    if (leave == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->map_select_l.rect.left = 3194 + 560;
    else if (leave == 1)
        d->map_select_l.rect.left = 3194 + 280;
    else
        d->map_select_l.rect.left = 3194;
}

void change_bouton_lr(sfRenderWindow *win, defender_t *d)
{
    sfFloatRect rectlarrow = sfSprite_getGlobalBounds(d->map_select_bl.sprite);
    sfFloatRect rectrarrow = sfSprite_getGlobalBounds(d->map_select_br.sprite);
    int l = sfFloatRect_contains(&rectlarrow, d->cursor.pos.x, d->cursor.pos.y);
    if (l == 1 && sfMouse_isButtonPressed(sfMouseLeft))
        d->map_select_bl.rect.left = 3053 + 560;
    else if (l == 1)
        d->map_select_bl.rect.left = 3053 + 280;
    else
        d->map_select_bl.rect.left = 3053;
    int r = sfFloatRect_contains(&rectrarrow, d->cursor.pos.x, d->cursor.pos.y);
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

void select_map(sfRenderWindow *w, defender_t *defender, game_t *game)
{
    if (sfMusic_getStatus(defender->menu_music) == 0)
        sfMusic_play(defender->menu_music);
    display_go(w, defender->menu);
    display_go(w, defender->map_select_b);
    display_go(w, defender->map_select_l);
    for (int i = 0; i < 4; i++)
        display_go(w, defender->map_select_m[i]);
    display_go(w, defender->map_select_bl);
    display_go(w, defender->map_select_br);
    display_bouton(w, defender->map_select_go);
    sfFloatRect rectmapselect_l = sfSprite_getGlobalBounds(defender->map_select_l.sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        defender->settings_click = 1;
    if (sfFloatRect_contains(&rectmapselect_l, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft && defender->settings_click == 1) {
        defender->settings_click = 0;
        defender->scene = MENU;
    }
    sfFloatRect rectmapselect_go = sfSprite_getGlobalBounds(defender->map_select_go.sprite);
    change_bouton_lr(w, defender);
    change_bouton_go(w, defender);
    change_bouton_leave_sm(w, defender);
    if (sfFloatRect_contains(&rectmapselect_go, defender->cursor.pos.x, defender->cursor.pos.y)
    && defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
        defender->settings_click = 0;
        sfMusic_stop(defender->menu_music);
        init_textures(defender, game);
        my_printf("%d\n", defender->map_select);
        defender->scene = GAME;
    }
    if (defender->event.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft)
        change_map(w, defender);
}
