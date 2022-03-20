/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause
*/

#include "my_defender.h"

void config_sound_2(sfRenderWindow *win, defender_t *def, game_t *game, int i)
{
    def->v_save = def->v_music == 0 ?
    def->v_save : def->v_music;
    def->v_buf_save = def->volume_buf == 0 ?
    def->v_buf_save : def->volume_buf;
    def->v_buf2_save = def->volume_buf2 == 0 ?
    def->v_buf2_save: def->volume_buf2;
}

void config_sound(sfRenderWindow *win, defender_t *def, game_t *game, int i)
{
    config_sound_2(win, def, game, i);
    if (i == 5) {
        sfMusic_setVolume(def->g_music, def->v_music
        == 0 ? def->v_save : 0);
    } else if (i == 6) {
        sfSound_setVolume(def->slash, def->volume_buf
        == 0 ? def->v_buf_save: 0);
        sfSound_setVolume(def->towertk, def->volume_buf
        == 0 ? def->v_buf_save: 0);
        sfSound_setVolume(def->towerpl, def->volume_buf
        == 0 ? def->v_buf_save: 0);
        sfSound_setVolume(def->towerdl, def->volume_buf
        == 0 ? def->v_buf_save: 0);
        for (int i = 0; i < 4; i++) {
            sfSound_setVolume(def->pop[i], def->volume_buf2 ==
            0 ? def->v_buf2_save: 0);
        }
    }
}
