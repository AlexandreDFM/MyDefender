/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "my_defender.h"

void next_wave(game_t *game, sfRenderWindow *win, defender_t *defender)
{
    game->bloon->pos.y = -50;
    if (defender->aplay == 1) {
        fill_waves(game);
        defender->state = 1;
        defender->playing = 1;
    } else {
        game->p_but[0].rect.left = 0;
        sfSprite_setTextureRect(game->p_but[0].sprite, game->p_but[0].rect);
        defender->state = 4;
        defender->playing = 0;
    }
}

void monkey_up_display(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    display_circle_hb(w, game->monkey->range);
    sfRenderWindow_drawSprite(w, game->monkey->sprite, NULL);
    display_go(w, game->monkey->avatar);
    skill_tree_display(w, game);
    sfRenderWindow_drawText(w, game->monkey->sell, NULL);
    sfRenderWindow_drawText(w, game->monkey->priority, NULL);
}

void game(sfRenderWindow *win, game_t *game_s, defender_t *defender)
{
    if (sfMusic_getStatus(defender->g_music) == 0)
        sfMusic_play(defender->g_music);
    sfRenderWindow_drawSprite(win, game_s->map, NULL);
    bloon_management(win, game_s, defender);
    ig_but(game_s, defender, win);
    sfRenderWindow_drawSprite(win, game_s->hud, NULL);
    sfRenderWindow_drawSprite(win, game_s->up_gui, NULL);
    sfRenderWindow_drawSprite(win, game_s->p_but[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, game_s->p_but[1].sprite, NULL);
    draw_score(win, game_s, defender);
    game_s->bloon = game_s->head;
    if (game_s->bloon == NULL || game_s->bloon->next == NULL) {
        next_wave(game_s, win, defender);
    }
    check_thud_hb(win, game_s, defender);
    monkey_management(win, game_s, defender);
    tower_attack(game_s, defender);
}
