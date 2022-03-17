/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

sfVector2f set_pos(int i, int offset)
{
    switch (i)
    {
    case 0: case 1: case 2: case 3: case 4:
        return (sfVector2f) {518 + offset * i, 384};
    case 5: case 6: case 7:
        return (sfVector2f) {618 + offset * (i - 4.5), 534};
    }
    return (sfVector2f) {0, 0};
}

defender_t init4(defender_t d)
{
    d.fps = 60;
    d.settings_click = 0;
    d.settings_l = create_go("maps/map_select.png", (sfVector2f) {600, 230}, (sfIntRect) {3194, 0, 138, 139}, (sfVector2f) {0.5, 0.5});
    d.settings = create_go("sprites/settings.png", (sfVector2f) {669, 300}, (sfIntRect) {0, 0, 582, 344}, (sfVector2f) {1, 1});
    d.settings_b = create_go("sprites/settings.png", (sfVector2f) {669, 300}, (sfIntRect) {582, 0, 582, 344}, (sfVector2f) {1, 1});
    d.settings_c = create_go("sprites/checked.png", (sfVector2f) {669 + 35 + 44 + 78, 560}, (sfIntRect) {0, 0, 48, 58}, (sfVector2f) {1, 1});
    d.settings_bar = c_r_hitbox((sfVector2f) {707, 395}, (sfIntRect) {0, 0, 510, 62}, (sfVector2f) {1, 1}, (sfColor) {0, 255, 0, 255});
    d.htpback = c_r_hitbox((sfVector2f) {100, 100}, (sfIntRect) {0, 0, 1720, 829}, (sfVector2f) {1, 1}, (sfColor) {0, 0, 0, 150});
    d.htp_leave = create_go("maps/map_select.png", (sfVector2f) {25, 25}, (sfIntRect) {3194, 0, 138, 139}, (sfVector2f) {0.5, 0.5});
    d.map_select_b = create_go("maps/map_select.png", (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 3053, 1716}, (sfVector2f) {0.62888961677, 0.59965034965});
    for (int i = 0, posx = 215, offsetx = 3053, offsety = 167; i < 4; i++, offsetx += 1000, posx += 500) {
        if (i == 2) offsetx = 3053, offsety += 721;
        if (i == 3) posx = 215;
        d.map_select_m[i] = create_go("maps/map_select.png", (sfVector2f) {posx, 300}, (sfIntRect) {offsetx, offsety, 1000, 720}, (sfVector2f) {0.5, 0.5});
    }
    d.map_select_bl = create_go("maps/map_select.png", (sfVector2f) {100, 450}, (sfIntRect) {3053, 0, 140, 139}, (sfVector2f) {0.5, 0.5});
    d.map_select_br = create_go("maps/map_select.png", (sfVector2f) {1820, 450}, (sfIntRect) {3053, 0, 140, 139}, (sfVector2f) {-0.5, 0.5});
    d.map_select_l = create_go("maps/map_select.png", (sfVector2f) {100, 100}, (sfIntRect) {3194, 0, 138, 139}, (sfVector2f) {0.5, 0.5});
    d.map_select_go = create_bouton("maps/map_select.png", (sfVector2f) {885 - 159 / 2, 825}, (sfIntRect) {4576, 0, 159, 43});
    d.map_select = 1;
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
        if (i < 4)
            d.p_menu.pause_b[i].rect = (sfIntRect)
            {0 + 126 * i, 127, 126, 127};
        else if (i == 4) {
            d.p_menu.pause_b[i].rect = (sfIntRect)
            {126 + indx, 127 + indy, 126, 127};
            indx += 252;
        } else {
            d.p_menu.pause_b[i].rect = (sfIntRect)
            {0 + indx, 127 + indy, 126, 127};
            indx += 252;
        }
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
    d.volume_buf = 50;
    d.volume_buf2 = 20;
    d.volume_music = 100;
    d.p_menu.fade = sfRectangleShape_create();
    sfRectangleShape_setSize(d.p_menu.fade, (sfVector2f) {1442, 1080});
    sfRectangleShape_setPosition(d.p_menu.fade, (sfVector2f) {237, 0});
    d.p_menu.color = sfColor_fromRGBA(0, 0, 0, 128);
    sfRectangleShape_setFillColor(d.p_menu.fade, d.p_menu.color);
    d.menu_music = sfMusic_createFromFile("./music/main_theme.ogg");
    d.game_music = sfMusic_createFromFile("./music/game_theme.ogg");
    d.slashbuffer = sfSoundBuffer_createFromFile("./sounds/schwing.ogg");
    d.slash = sfSound_create();
    sfSound_setBuffer(d.slash, d.slashbuffer);
    sfSound_setVolume(d.slash, 50);
    d.popbuffer[0] = sfSoundBuffer_createFromFile("./sounds/pop1.ogg");
    d.popbuffer[1] = sfSoundBuffer_createFromFile("./sounds/pop2.ogg");
    d.popbuffer[2] = sfSoundBuffer_createFromFile("./sounds/pop3.ogg");
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
    return init3(d);
}

defender_t init(void)
{
    defender_t defender;
    defender.intro = create_go("./sprites/ninja.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 383, 204}, (sfVector2f) {5.01305483029, 5.04411764706});
    defender.menu = create_go("./sprites/back_menu.png", (sfVector2f) {-84, 0},
    (sfIntRect) {0, 0, 720, 360}, (sfVector2f) {2.9, 2.9});
    defender.title = create_go("./sprites/bloons_logo.png",
    (sfVector2f) {769.5, 10},(sfIntRect) {0, 0, 796, 612},
    (sfVector2f) {0.5, 0.5});
    for (int i = 0, posy = 400, rectl = 0 ; i < 4;
    i++, posy += 106, rectl += 43)
        defender.bouton[i] = create_bouton("./sprites/menu_buttons.png",
        (sfVector2f) {805, posy}, (sfIntRect) {0, rectl, 159, 43});
    defender.cursor = create_cursor("./sprites/cursor.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 64, 64});
    defender.clockintro = sfClock_create();
    defender.scene = INTRO;
    defender.playing = 0;
    defender.state = 0;
    defender.aplay = 0;
    return init2(defender);
}
