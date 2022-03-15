/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

void uninit_textures_2(game_t *game)
{
    sfFont_destroy(game->font);
    sfClock_destroy(game->c);
    sfText_destroy(game->h);
    sfText_destroy(game->sc);
    sfText_destroy(game->wav);
    game->cleared = 1;
}

void uninit_textures(game_t *game)
{
    int i = 0;
    char **array = my_strtwa(get_lines("sprites/textures.txt"), "\n");
    for (; array[i] != 0; i++);
    for (int j = 0; j < i - 1; j++)
        sfTexture_destroy(game->t_array[j]);
    my_free_array(array);
    my_free_array(game->tower_stats);
    sfSprite_destroy(game->hud);
    sfSprite_destroy(game->map);
    sfSprite_destroy(game->up_gui);
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(game->p_but[i].sprite);
    sfImage_destroy(game->map_c);
    free(game->colors);
    free(game->dirs);
    uninit_textures_2(game);
}
