/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** tower_management
*/

#include "my_defender.h"

void bloon_management(sfRenderWindow *win, game_t *g, defender_t *defender)
{
    while (g->bloon != NULL && g->bloon->next != NULL
    && defender->playing == 1) {
        if (sfFloatRect_contains(&g->frame,
        g->bloon->pos.x, g->bloon->pos.y)) {
            sfRenderWindow_drawSprite(win, g->bloon->sprite, NULL);
            sfSprite_setPosition(g->bloon->sprite, g->bloon->pos);
            check_pos(g, win);
        }
        if (sfClock_getElapsedTime(g->c).microseconds > 400) {
            g->bloon->pos.x += g->bloon->dir.x *
            g->bloon->speed * g->ff;
            g->bloon->pos.y += g->bloon->dir.y *
            g->bloon->speed * g->ff;
            sfClock_restart(g->c);
            g->bloon = g->bloon->next;
        }
    }
}

void monkey_management_2(sfRenderWindow *w, game_t *game, defender_t *d)
{
    sfFloatRect s_rect =
    sfRectangleShape_getGlobalBounds(game->monkey->hitbox_sell.shape);
    if (d->cursor.t_to == NO_MONKEY &&
    sfFloatRect_contains(&s_rect, d->cursor.pos.x,
    d->cursor.pos.y) && sfMouse_isButtonPressed(sfMouseLeft)) {
        char **stats = my_strtwa(game->tower_stats[tower(game->monkey->type)
        == 0 ? 1 : tower(game->monkey->type) * 9 + 1], "|");
        game->money += my_atoi(stats[20]) * 90 / 100;
        my_free_array(stats);
        sfSound_play(d->towerdl);
        delete_tower(game);
    }
}

void monkey_management_3(sfRenderWindow *w, game_t *game, defender_t *d)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->monkey->sprite);
    if (d->cursor.t_to == NO_MONKEY &&
    sfFloatRect_contains(&rect, d->cursor.pos.x,
    d->cursor.pos.y) && sfMouse_isButtonPressed(sfMouseLeft)) {
        d->cursor.t_to = MONKEY_SELECT;
        game->monkey->clicked = TRUE;
    } else if (d->cursor.t_to == MONKEY_SELECT
    && game->monkey->clicked == TRUE) {
        monkey_up_display(w, game, d);
    } else {
        if (game->monkey != NULL)
            game->monkey->clicked = FALSE;
    }
}

void monkey_management(sfRenderWindow *w, game_t *game, defender_t *d)
{
    while (game->monkey != NULL) {
        sfRenderWindow_drawSprite(w, game->monkey->sprite, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        d->cursor.t_to == MONKEY_SELECT
        && game->monkey->clicked == TRUE) d->cursor.t_to = NO_MONKEY;
        monkey_management_2(w, game, d);
        monkey_management_3(w, game, d);
        if (game->monkey != NULL)
            game->monkey = game->monkey->next;
    }
    game->monkey = game->monkey_head;
}
