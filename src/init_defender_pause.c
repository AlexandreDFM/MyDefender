/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** init_defender_pause
*/

#include "my_defender.h"

defender_t condition_init(defender_t d, int i, int *ix, int iy)
{
    if (i < 4) {
        d.p_menu.pause_b[i].rect = (sfIntRect){0 + 126 * i, 127, 126, 127};
    } else if (i == 4) {
        d.p_menu.pause_b[i].rect = (sfIntRect){126 + *ix, 127 + iy, 126, 127};
        *ix += 252;
    } else {
        d.p_menu.pause_b[i].rect = (sfIntRect){0 + *ix, 127 + iy, 126, 127};
        *ix += 252;
    }
    return d;
}
