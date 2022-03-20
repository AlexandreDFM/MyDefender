/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-mydefender-antoine.frankel
** File description:
** skill_tree
*/

#include "my_defender.h"

void skill_tree_display(sfRenderWindow *w, game_t *game)
{
    if (game->monkey->price1 <= game->money ) {
        display_go(w, game->monkey->upgrade1);
    } else {
        display_go(w, game->monkey->upgrade1);
        display_rect_hb(w, game->monkey->hitbox_up1);
    }
    if (game->monkey->price2 <= game->money ) {
        display_go(w, game->monkey->upgrade2);
    } else {
        display_go(w, game->monkey->upgrade2);
        display_rect_hb(w, game->monkey->hitbox_up2);
    }
}

void skill_tree_2(game_t *g, defender_t *defender)
{
    sfFloatRect rect2 = sfSprite_getGlobalBounds(g->monkey->upgrade2.sprite);
    if (sfFloatRect_contains(&rect2, defender->cursor.pos.x,
    defender->cursor.pos.y) && g->monkey->lvl1 < g->monkey->lvl2
    && g->monkey->lvl2 <= 4) {
        char **path = my_strtwa(g->tower_stats[tower(g->monkey->type)
        + 1 * g->monkey->lvl2], "|");
        g->monkey->lvl2 += 1;
        sfIntRect rect = {0, 0, 0, 0};
        sfSprite_setTextureRect(g->monkey->sprite, rect);
        my_free_array(path);
        return;
    }
}

void skill_tree(game_t *g, defender_t *defender)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(g->monkey->upgrade1.sprite);
    if (sfFloatRect_contains(&rect1,
    defender->cursor.pos.x, defender->cursor.pos.y)
    && g->monkey->lvl2 < g->monkey->lvl1 && g->monkey->lvl1 <= 4) {
        char **path = my_strtwa(g->tower_stats[tower(g->monkey->type)
        + 1 * g->monkey->lvl1], "|");
        g->monkey->lvl1 += 1;
        sfIntRect rect = {0, 0, 0, 0};
        sfSprite_setTextureRect(g->monkey->sprite, rect);
        my_free_array(path);
        return;
    }
    skill_tree_2(g, defender);
}
