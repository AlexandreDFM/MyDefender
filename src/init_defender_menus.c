/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

defender_t init_settings(defender_t d)
{
    d.fps = 60;
    d.settings_click = 0;
    d.difficulty = EASY;
    d.settings_l = create_go("maps/map_select.png", (sfVector2f) {600, 230},
    (sfIntRect) {3194, 0, 138, 139}, (sfVector2f) {0.5, 0.5});
    d.settings = create_go("sprites/settings.png", (sfVector2f) {669, 300},
    (sfIntRect) {0, 0, 582, 344}, (sfVector2f) {1, 1});
    d.settings_b = create_go("sprites/settings.png", (sfVector2f) {669, 300},
    (sfIntRect) {582, 0, 582, 344}, (sfVector2f) {1, 1});
    d.settings_c = create_go("sprites/checked.png",
    (sfVector2f) {669 + 35 + 44 + 78, 560}, (sfIntRect)
    {0, 0, 48, 58}, (sfVector2f) {1, 1});
    d.settings_bar = c_r_hitbox((sfVector2f) {707, 395},
    (sfIntRect) {0, 0, 510, 62}, (sfVector2f) {1, 1},
    (sfColor) {0, 255, 0, 255});
    return d;
}

defender_t init_htp(defender_t d)
{
    d.htpback = c_r_hitbox((sfVector2f) {100, 100},
    (sfIntRect) {0, 0, 1720, 829}, (sfVector2f) {1, 1},
    (sfColor) {0, 0, 0, 150});
    d.htp_leave = create_go("maps/map_select.png", (sfVector2f) {25, 25},
    (sfIntRect) {3194, 0, 138, 139}, (sfVector2f) {0.5, 0.5});
    return d;
}

defender_t init_map_select1(defender_t d)
{
    d.map_select_b = create_go("maps/map_select.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 3053, 1716},
    (sfVector2f) {0.62888961677, 0.59965034965});
    for (int i = 0, posx = 215, offsetx = 3053, offsety = 167; i < 4; i++,
    offsetx += 1000, posx += 500) {
        if (i == 2) offsetx = 3053, offsety += 721;
        if (i == 3) posx = 215;
        d.map_select_m[i] = create_go("maps/map_select.png",
        (sfVector2f) {posx, 300}, (sfIntRect) {offsetx, offsety, 1000, 720},
        (sfVector2f) {0.5, 0.5});
    }
    return d;
}

defender_t init_map_select2(defender_t d)
{
    d.map_select_bl = create_go("maps/map_select.png", (sfVector2f) {100, 450},
    (sfIntRect) {3053, 0, 140, 139}, (sfVector2f) {0.5, 0.5});
    d.map_select_br = create_go("maps/map_select.png", (sfVector2f)
    {1820, 450}, (sfIntRect) {3053, 0, 140, 139}, (sfVector2f) {-0.5, 0.5});
    d.map_select_l = create_go("maps/map_select.png", (sfVector2f) {100, 100},
    (sfIntRect) {3194, 0, 138, 139}, (sfVector2f) {0.5, 0.5});
    d.map_select_d = create_go("maps/map_select.png", (sfVector2f) {314, 783},
    (sfIntRect) {3947, 0, 96, 98},
    (sfVector2f) {0.62888961677, 0.59965034965});
    d.map_select_go = create_bouton("maps/map_select.png",
    (sfVector2f) {885 - 159 / 2, 875}, (sfIntRect) {4576, 0, 159, 43});
    d.map_select = 1;
    return d;
}

defender_t init_menu_boutons(defender_t defender)
{
    defender.menu = create_go("./sprites/back_menu.png", (sfVector2f) {-84, 0},
    (sfIntRect) {0, 0, 720, 360}, (sfVector2f) {2.9, 2.9});
    defender.title = create_go("./sprites/bloons_logo.png",
    (sfVector2f) {769.5, 10},(sfIntRect) {0, 0, 796, 612},
    (sfVector2f) {0.5, 0.5});
    for (int i = 0, posy = 400, rectl = 0 ; i < 6;
    i++, posy += 106, rectl += 43) {
        if (i == 4) posy = 400;
        if (i == 5) posy = 559;
        defender.bouton[i] = create_bouton("./sprites/menu_buttons.png",
        (sfVector2f) {805, posy}, (sfIntRect) {0, rectl, 159, 43});
    }
    return defender;
}
