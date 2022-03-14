/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "my_defender.h"

void draw_score(game_t *game, sfRenderWindow *win)
{
    sfText_setString(game->sc, my_itoa(game->money));
    sfText_setString(game->h, my_itoa(game->health));
    sfRenderWindow_drawText(win, game->sc, NULL);
    sfRenderWindow_drawText(win, game->h, NULL);
}

void next_wave(game_t *game, sfRenderWindow *win, defender_t *defender)
{
    game->bloon->pos.y = -50;
    if (defender->aplay == 1) {
        fill_waves(game);
        defender->state = 1;
        defender->playing = 1;
    }else {
        game->p_but[0].rect.left = 0;
        sfSprite_setTextureRect(game->p_but[0].sprite, game->p_but[0].rect);
        defender->state = 4;
        defender->playing = 0;
    }

}

void monkey_up_display(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    display_monkey_hb(w, game->monkey->range);
    sfRenderWindow_drawSprite(w, game->monkey->sprite, NULL);
    display_go(w, game->monkey->avatar);
    display_go(w, game->monkey->upgrade1);
    display_go(w, game->monkey->upgrade2);
    sfRenderWindow_drawText(w, game->monkey->sell, NULL);
    sfRenderWindow_drawText(w, game->monkey->priority, NULL);
}

void monkey_upgrade(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    game->monkey->sell = sfText_create();
    sfText_setString(game->monkey->sell, "SELL");
    sfText_setFont(game->monkey->sell, game->font);
    sfText_setCharacterSize(game->monkey->sell, 40);
    sfText_setPosition(game->monkey->sell, (sfVector2f) {650, 950});
    game->monkey->priority = sfText_create();
    sfText_setString(game->monkey->priority, "PRIORITY");
    sfText_setFont(game->monkey->priority, game->font);
    sfText_setCharacterSize(game->monkey->priority, 40);
    sfText_setPosition(game->monkey->priority, (sfVector2f) {540, 1010});
    game->monkey->hitbox_sell.shape = sfRectangleShape_create();
    game->monkey->hitbox_sell.rect = (sfIntRect) {0, 0, 165, 45};
    game->monkey->hitbox_sell.color = (sfColor) {0, 0, 255, 100};
    game->monkey->hitbox_sell.pos = (sfVector2f) {610, 950};
    sfRectangleShape_setFillColor(game->monkey->hitbox_sell.shape, game->monkey->hitbox_sell.color);
    sfRectangleShape_setSize(game->monkey->hitbox_sell.shape, (sfVector2f) {game->monkey->hitbox_sell.rect.width, game->monkey->hitbox_sell.rect.height});
    sfRectangleShape_setPosition(game->monkey->hitbox_sell.shape, game->monkey->hitbox_sell.pos);
}

void monkey_management(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    while (game->monkey != NULL) {
        sfRenderWindow_drawSprite(w, game->monkey->sprite, NULL);
        sfFloatRect rect = sfSprite_getGlobalBounds(game->monkey->sprite);
        sfFloatRect s_rect = sfRectangleShape_getGlobalBounds(game->monkey->hitbox_sell.shape);
        if (sfMouse_isButtonPressed(sfMouseLeft) && defender->cursor.t_to == MONKEY_SELECT && game->monkey->clicked == TRUE) defender->cursor.t_to = NO_MONKEY;
        if (defender->cursor.t_to == NO_MONKEY && sfFloatRect_contains(&s_rect, defender->cursor.pos.x, defender->cursor.pos.y) && sfMouse_isButtonPressed(sfMouseLeft)) {
            delete_tower(game);
            sfSound_play(defender->towerdl);
        }
        if (defender->cursor.t_to == NO_MONKEY && sfFloatRect_contains(&rect, defender->cursor.pos.x, defender->cursor.pos.y) && sfMouse_isButtonPressed(sfMouseLeft)) {
            defender->cursor.t_to = MONKEY_SELECT;
            game->monkey->clicked = TRUE;
            monkey_upgrade(w, game, defender);
        } else if (defender->cursor.t_to == MONKEY_SELECT && game->monkey->clicked == TRUE) {
            monkey_up_display(w, game, defender);
        } else {
            if (game->monkey != NULL)
                game->monkey->clicked = FALSE;
        }
        if (game->monkey != NULL)
            game->monkey = game->monkey->next;
    }
    game->monkey = game->monkey_head;
}

void game(sfRenderWindow *win, game_t *game_s, defender_t *defender)
{
    if (sfMusic_getStatus(defender->game_music) == 0)
        sfMusic_play(defender->game_music);
    sfRenderWindow_drawSprite(win, game_s->map, NULL);
    while (game_s->bloon != NULL && game_s->bloon->next != NULL && defender->playing == 1) {
        if (sfFloatRect_contains(&game_s->frame, game_s->bloon->pos.x, game_s->bloon->pos.y)){
            sfRenderWindow_drawSprite(win, game_s->bloon->sprite, NULL);
            sfSprite_setPosition(game_s->bloon->sprite, game_s->bloon->pos);
            check_pos(game_s, win);
        }
        if (sfClock_getElapsedTime(game_s->c).microseconds > 40) {
            game_s->bloon->pos.x += game_s->bloon->dir.x * game_s->bloon->speed * game_s->ff;
            game_s->bloon->pos.y += game_s->bloon->dir.y * game_s->bloon->speed * game_s->ff;
            sfClock_restart(game_s->c);
            game_s->bloon = game_s->bloon->next;
        }
    }
    ig_but(game_s, defender, win);
    sfRenderWindow_drawSprite(win, game_s->hud, NULL);
    sfRenderWindow_drawSprite(win, game_s->up_gui, NULL);
    sfRenderWindow_drawSprite(win, game_s->p_but[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, game_s->p_but[1].sprite, NULL);
    draw_score(game_s, win);
    game_s->bloon = game_s->head;
    if (game_s->bloon == NULL || game_s->bloon->next == NULL) {
        next_wave(game_s, win, defender);
    }
    check_thud_hb(win, game_s, defender);
    monkey_management(win, game_s, defender);
    tower_attack(game_s, defender);
}
