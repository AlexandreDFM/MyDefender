/*
** EPITECH PROJECT, 2022
** score
** File description:
** Function about score
*/

#include "my_defender.h"

void draw_score(sfRenderWindow *win, game_t *game, defender_t *defender)
{
    if (defender->scene != GAMEOVER && game->health <= 0) {
        game->health = 0;
        game->gamestate = create_text(game->font,
        (sfVector2f) {775, 270}, "GAME OVER", 100);
        defender->scene = GAMEOVER;
    }
    sfText_setString(game->sc, my_itoa(game->money));
    sfText_setString(game->h, my_itoa(game->health));
    sfText_setString(game->wav, my_strcat_alloc("Wave : ",
    my_itoa(game->wave_nb)));
    sfRenderWindow_drawText(win, game->sc, NULL);
    sfRenderWindow_drawText(win, game->h, NULL);
    sfRenderWindow_drawText(win, game->wav, NULL);
}
