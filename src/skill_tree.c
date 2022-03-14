/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** skill_tree
*/

#include "my_defender.h"

void skill_tree_display(sfRenderWindow *w, game_t *game)
{
    if (price1 <= game->money ) {
        display_go(w, game->monkey->upgrade1);
    }
    if (price2 <= game->money ) {
        display_go(w, game->monkey->upgrade2);
    }
}

void skill_tree(game_t *game, defender_t *defender)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(game->monkey->upgrade1.sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(game->monkey->upgrade2.sprite);
    if (sfFloatRect_contains(&rect1, defender->cursor.pos.x, defender->cursor.pos.y) && game->monkey->lvl2 < game->monkey->lvl1 && game->monkey->lvl1 <= 4) {
        char **path = my_strtwa(game->tower_stats[tower(game->monkey->type) + 1 * game->monkey->lvl1], "|");
        game->monkey->lvl1 += 1;
        sfIntRect rect = {};
        sfSprite_setTextureRect(game->monkey->sprite, rect);
        my_free_array(path);
        return;
    }
    if (sfFloatRect_contains(&rect2, defender->cursor.pos.x, defender->cursor.pos.y) do && game->monkey->lvl1 < game->monkey->lvl2 && game->monkey->lvl2 <= 4) {
        char **path = my_strtwa(game->tower_stats[tower(game->monkey->type) + 1 * game->monkey->lvl2], "|");
        game->monkey->lvl2 += 1;
        sfIntRect rect = {};
        sfSprite_setTextureRect(game->monkey->sprite, rect);
        my_free_array(path);
        return;
    }
}
