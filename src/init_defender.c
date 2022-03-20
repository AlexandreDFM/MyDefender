/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

sfVector2f set_pos(int i, int offset)
{
    switch (i) {
    case 0: case 1: case 2: case 3: case 4:
        return (sfVector2f) {518 + offset * i, 384};
    case 5: case 6: case 7:
        return (sfVector2f) {618 + offset * (i - 4.5), 534};
    }
    return (sfVector2f) {0, 0};
}

defender_t init4(defender_t d)
{
    d = init_settings(d);
    d = init_htp(d);
    d = init_map_select1(d);
    d = init_map_select2(d);
    return d;
}

defender_t init3(defender_t d)
{
    int indx = 0, indy = 127;
    int offset = 200;
    sfTexture *texture = sfTexture_createFromFile("sprites/game_button.png",
    NULL);
    for (int i = 0; i < 8; i++) {
        d.p_menu.pause_b[i].texture = texture;
        d.p_menu.pause_b[i].sprite = sfSprite_create();
        sfSprite_setTexture(d.p_menu.pause_b[i].sprite, texture, sfTrue);
        sfSprite_setOrigin(d.p_menu.pause_b[i].sprite,
        (sfVector2f) {63, 63.5});
        d.p_menu.pause_b[i].pos = set_pos(i, offset);
        d = condition_init(d, i, &indx, indy);
        if (i == 5) indx = 0, indy += 127;
        sfSprite_setPosition(d.p_menu.pause_b[i].sprite,
        d.p_menu.pause_b[i].pos);
        sfSprite_setTextureRect(d.p_menu.pause_b[i].sprite,
        d.p_menu.pause_b[i].rect);
    }
    return init4(d);
}

defender_t init2(defender_t d)
{
    d = init_music1(d);
    d = init_music2(d);
    d = init_music3(d);
    return init3(d);
}

defender_t init(void)
{
    defender_t defender;
    defender.intro = create_go("./sprites/ninja.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 383, 204}, (sfVector2f) {5.01305483029, 5.04411764706});
    defender = init_menu_boutons(defender);
    defender.cursor = create_cursor("./sprites/cursor.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 64, 64});
    defender.clockintro = sfClock_create();
    defender.scene = INTRO;
    defender.playing = 0;
    defender.state = 0;
    defender.aplay = 0;
    return init2(defender);
}
