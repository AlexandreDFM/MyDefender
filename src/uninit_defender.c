/*
** EPITECH PROJECT, 2022
** uninit
** File description:
** Function to uninit game
*/

#include "my_defender.h"

void uninit3(defender_t *defender)
{
    for (int i = 0; i < 8; i++)
        sfSprite_destroy(defender->p_menu.pause_b[i].sprite);
}

void uninit2(defender_t *defender)
{
    sfRectangleShape_destroy(defender->p_menu.fade);
    sfMusic_destroy(defender->menu_music);
    sfMusic_destroy(defender->game_music);
    sfSoundBuffer_destroy(defender->slashbuffer);
        sfSound_destroy(defender->slash);
    for (int i = 0 ; i < 4; i++) {
        sfSoundBuffer_destroy(defender->popbuffer[i]);
        sfSound_destroy(defender->pop[i]);
    }
    sfSoundBuffer_destroy(defender->towertkbuffer);
    sfSound_destroy(defender->towertk);
    sfSoundBuffer_destroy(defender->towerplbuffer);
    sfSound_destroy(defender->towerpl);
    sfSoundBuffer_destroy(defender->towerdlbuffer);
    sfSound_destroy(defender->towerdl);
    sfText_destroy(defender->help_txt);
    sfFont_destroy(defender->font);
    uninit3(defender);
}

void uninit(defender_t *defender)
{
    sfSprite_destroy(defender->intro.sprite);
    sfSprite_destroy(defender->menu.sprite);
    sfSprite_destroy(defender->title.sprite);
    for (int i = 0; i < 4; i++)
        sfSprite_destroy(defender->bouton[i].sprite);
    sfSprite_destroy(defender->cursor.sprite);
    sfCircleShape_destroy(defender->cursor.monkey_c.shape);
    sfSprite_destroy(defender->cursor.monkey.sprite);
    sfClock_destroy(defender->clockintro);
    uninit2(defender);
}

void all_uninit(defender_t *defender, game_t *game)
{
    uninit(defender);
    if (game->cleared == 0)
        uninit_textures(game);
}
