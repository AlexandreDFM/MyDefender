/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

defender_t init_music1(defender_t d)
{
    d.volume_buf = 50;
    d.volume_buf2 = 20;
    d.v_music = 100;
    d.p_menu.fade = sfRectangleShape_create();
    sfRectangleShape_setSize(d.p_menu.fade, (sfVector2f) {1442, 1080});
    sfRectangleShape_setPosition(d.p_menu.fade, (sfVector2f) {237, 0});
    d.p_menu.color = sfColor_fromRGBA(0, 0, 0, 128);
    sfRectangleShape_setFillColor(d.p_menu.fade, d.p_menu.color);
    d.m_music = sfMusic_createFromFile("./music/main_theme.ogg");
    d.g_music = sfMusic_createFromFile("./music/game_theme.ogg");
    d.slashbuffer = sfSoundBuffer_createFromFile("./sounds/schwing.ogg");
    d.slash = sfSound_create();
    sfSound_setBuffer(d.slash, d.slashbuffer);
    sfSound_setVolume(d.slash, 50);
    d.popbuffer[0] = sfSoundBuffer_createFromFile("./sounds/pop1.ogg");
    d.popbuffer[1] = sfSoundBuffer_createFromFile("./sounds/pop2.ogg");
    d.popbuffer[2] = sfSoundBuffer_createFromFile("./sounds/pop3.ogg");
    return d;
}

defender_t init_music2(defender_t d)
{
    d.popbuffer[3] = sfSoundBuffer_createFromFile("./sounds/pop4.ogg");
    for (int i = 0 ; i < 4; i++) {
        d.pop[i] = sfSound_create();
        sfSound_setBuffer(d.pop[i], d.popbuffer[i]);
        sfSound_setVolume(d.pop[i], 20);
    }
    d.towertkbuffer =
    sfSoundBuffer_createFromFile("./sounds/tower_select.ogg");
    d.towertk = sfSound_create();
    sfSound_setBuffer(d.towertk, d.towertkbuffer);
    sfSound_setVolume(d.towertk, 50);
    d.towerplbuffer =
    sfSoundBuffer_createFromFile("./sounds/tower_place.ogg");
    d.towerpl = sfSound_create();
    sfSound_setBuffer(d.towerpl, d.towerplbuffer);
    sfSound_setVolume(d.towerpl, 50);
    return d;
}

defender_t init_music3(defender_t d)
{
    d.towerdlbuffer =
    sfSoundBuffer_createFromFile("./sounds/sell_tower.ogg");
    d.towerdl = sfSound_create();
    sfSound_setBuffer(d.towerdl, d.towerdlbuffer);
    sfSound_setVolume(d.towerdl, 50);
    d.font = sfFont_createFromFile("./font/font_htp.ttf");
    d.help_txt = sfText_create();
    sfText_setString(d.help_txt, get_lines("./how_to_play/help.txt"));
    sfText_setFont(d.help_txt, d.font);
    sfText_setPosition(d.help_txt, (sfVector2f) {100, 100});
    sfText_setCharacterSize(d.help_txt, 30);
    return d;
}
