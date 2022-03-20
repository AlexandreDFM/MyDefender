/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** init_defender_pause
*/

#include "my_defender.h"

defender_t condition_init(defender_t d, int i, int *indx, int indy)
{
    if (i < 4) {
        d.p_menu.pause_b[i].rect = (sfIntRect)
        {0 + 126 * i, 127, 126, 127};
    } else if (i == 4) {
        d.p_menu.pause_b[i].rect = (sfIntRect)
        {126 + *indx, 127 + indy, 126, 127};
        *indx += 252;
    } else {
        d.p_menu.pause_b[i].rect = (sfIntRect)
        {0 + *indx, 127 + indy, 126, 127};
        *indx += 252;
    }
    return d;
}
