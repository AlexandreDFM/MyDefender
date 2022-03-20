/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause
*/

#include "my_defender.h"

void config_sound_2(sfRenderWindow *win, defender_t *defender, game_t *game, int i)
{
    defender->v_save = defender->v_music == 0 ?
    defender->v_save : defender->v_music;
    defender->v_buf_save = defender->volume_buf == 0 ?
    defender->v_buf_save : defender->volume_buf;
    defender->v_buf2_save = defender->volume_buf2 == 0 ?
    defender->v_buf2_save: defender->volume_buf2;
}

void config_sound(sfRenderWindow *win, defender_t *defender, game_t *game, int i)
{
    config_sound_2(win, defender, game, i);
    if (i == 5) {
        sfMusic_setVolume(defender->g_music, defender->v_music
        == 0 ? defender->v_save : 0);
    } else if (i == 6) {
        sfSound_setVolume(defender->slash, defender->volume_buf
        == 0 ? defender->v_buf_save: 0);
        sfSound_setVolume(defender->towertk, defender->volume_buf
        == 0 ? defender->v_buf_save: 0);
        sfSound_setVolume(defender->towerpl, defender->volume_buf
        == 0 ? defender->v_buf_save: 0);
        sfSound_setVolume(defender->towerdl, defender->volume_buf
        == 0 ? defender->v_buf_save: 0);
        for (int i = 0; i < 4; i++) {
            sfSound_setVolume(defender->pop[i], defender->volume_buf2 ==
            0 ? defender->v_buf2_save: 0);
        }
    }
}
