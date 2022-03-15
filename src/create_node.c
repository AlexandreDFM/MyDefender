/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** creation_node
*/

#include "my_defender.h"

void tower_node(sfRenderWindow *w, game_t *game, defender_t *d)
{
    if (game->monkey_head == NULL) {
        game->monkey = first_monkey(game, d,
        (sfVector2f) {d->cursor.pos.x, d->cursor.pos.y});
        game->monkey_head = game->monkey;
        char **money = my_strtwa(game->tower_stats[tower(d->cursor.t_to) == 0
        ? 1 : tower(d->cursor.t_to) * 9 + 1], "|");
        game->money -= my_atoi(money[20]);
        my_free_array(money);
        sfSound_play(d->towerpl);
    } else {
        add_monkey(game, d,
        (sfVector2f) {d->cursor.pos.x, d->cursor.pos.y});
        char **money = my_strtwa(game->tower_stats[tower(d->cursor.t_to) == 0
        ? 1 : tower(d->cursor.t_to) * 9 + 1], "|");
        game->money -= my_atoi(money[20]);
        my_free_array(money);
        sfSound_play(d->towerpl);
    }
}
