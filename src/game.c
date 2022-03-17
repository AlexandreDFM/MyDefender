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
    // sfRenderWindow_drawRectangleShape(w, game->monkey->hitbox_sell.shape, NULL);
    sfRenderWindow_drawText(w, game->monkey->sell, NULL);
    sfRenderWindow_drawText(w, game->monkey->priority, NULL);
}

void monkey_upgrade(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    game->monkey->sell = sfText_create();
    sfText_setString(game->monkey->sell, "SELL");
    sfText_setFont(game->monkey->sell, game->font);
    sfText_setCharacterSize(game->monkey->sell, 40);
    sfText_setPosition(game->monkey->sell, (sfVector2f) {650, 905});
    game->monkey->priority = sfText_create();
    sfText_setString(game->monkey->priority, "PRIORITY");
    sfText_setFont(game->monkey->priority, game->font);
    sfText_setCharacterSize(game->monkey->priority, 40);
    sfText_setPosition(game->monkey->priority, (sfVector2f) {540, 1010});
    game->monkey->hitbox_sell.shape = sfRectangleShape_create();
    game->monkey->hitbox_sell.rect = (sfIntRect) {0, 0, 165, 45};
    game->monkey->hitbox_sell.color = (sfColor) {0, 0, 255, 100};
    game->monkey->hitbox_sell.pos = (sfVector2f) {610, 910};
    sfRectangleShape_setFillColor(game->monkey->hitbox_sell.shape,
    game->monkey->hitbox_sell.color);
    sfRectangleShape_setSize(game->monkey->hitbox_sell.shape,
    (sfVector2f) {game->monkey->hitbox_sell.rect.width,
    game->monkey->hitbox_sell.rect.height});
    sfRectangleShape_setPosition(game->monkey->hitbox_sell.shape,
    game->monkey->hitbox_sell.pos);
}

void monkey_management(sfRenderWindow *w, game_t *game, defender_t *d)
{
    while (game->monkey != NULL) {
        sfRenderWindow_drawSprite(w, game->monkey->sprite, NULL);
        sfFloatRect rect = sfSprite_getGlobalBounds(game->monkey->sprite);
        sfFloatRect s_rect =
        sfRectangleShape_getGlobalBounds(game->monkey->hitbox_sell.shape);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        d->cursor.t_to == MONKEY_SELECT
        && game->monkey->clicked == TRUE) d->cursor.t_to = NO_MONKEY;
        if (d->cursor.t_to == NO_MONKEY &&
        sfFloatRect_contains(&s_rect, d->cursor.pos.x,
        d->cursor.pos.y) && sfMouse_isButtonPressed(sfMouseLeft)) {
            // char **stats = my_strtwa(game->tower_stats[tower(game->monkey->type) == 0
            // ? 1 : tower(game->monkey->type) * 9 + 1], "|");
            // game->money += my_atoi(stats[20]);
            // sfSound_play(d->towerdl);
            // free(stats);
            delete_tower(game);
        }
        if (d->cursor.t_to == NO_MONKEY &&
        sfFloatRect_contains(&rect, d->cursor.pos.x,
        d->cursor.pos.y) && sfMouse_isButtonPressed(sfMouseLeft)) {
            d->cursor.t_to = MONKEY_SELECT;
            game->monkey->clicked = TRUE;
            monkey_upgrade(w, game, d);
        } else if (d->cursor.t_to == MONKEY_SELECT
        && game->monkey->clicked == TRUE) {
            monkey_up_display(w, game, d);
        } else {
            if (game->monkey != NULL)
                game->monkey->clicked = FALSE;
        }
        if (game->monkey != NULL)
            game->monkey = game->monkey->next;
    }
    game->monkey = game->monkey_head;
}

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
        if (sfClock_getElapsedTime(g->c).microseconds > 40) {
            g->bloon->pos.x += g->bloon->dir.x *
            g->bloon->speed * g->ff;
            g->bloon->pos.y += g->bloon->dir.y *
            g->bloon->speed * g->ff;
            sfClock_restart(g->c);
            g->bloon = g->bloon->next;
        }
    }
}

void game(sfRenderWindow *win, game_t *game_s, defender_t *defender)
{
    if (sfMusic_getStatus(defender->game_music) == 0)
        sfMusic_play(defender->game_music);
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
