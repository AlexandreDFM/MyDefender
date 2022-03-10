/*
** EPITECH PROJECT, 2022
** tower_nodes
** File description:
** Function about node of Towers
*/

#include "my_defender.h"

void add_icons(game_t *game, defender_t *defender, monkey_t *obj)
{
    char **stats = my_strtwa(game->tower_stats[tower(defender->cursor.t_to)
    == 0 ? 1 : tower(defender->cursor.t_to) * 9 + 1], "|");
    obj->avatar = create_go("./sprites/avatar_icons.png", (sfVector2f)
    {260, 925}, (sfIntRect) {my_atoi(stats[8]), my_atoi(stats[9]),
    my_atoi(stats[10]), my_atoi(stats[11])}, (sfVector2f) {0.5, 0.5});
    obj->upgrade1 = create_go("./sprites/upgrades_icons.png", (sfVector2f)
    {980, 930},
    (sfIntRect) {my_atoi(stats[12]), my_atoi(stats[13]),
    my_atoi(stats[14]), my_atoi(stats[15])}, (sfVector2f) {0.75, 0.75});
    obj->upgrade2 = create_go("./sprites/upgrades_icons.png", (sfVector2f)
    {1300, 930},
    (sfIntRect) {my_atoi(stats[16]), my_atoi(stats[17]),
    my_atoi(stats[18]), my_atoi(stats[19])}, (sfVector2f) {0.75, 0.75});
    free(stats);
}

monkey_t *first_monkey(game_t *game, defender_t *defender, sfVector2f pos)
{
    monkey_t *obj = malloc(sizeof(monkey_t));
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->resize = (sfVector2f) {0.75, 0.75};
    add_icons(game, defender, obj);
    sfSprite_setTexture(obj->sprite, game->t_monkey, sfTrue);
    sfSprite_setTextureRect(obj->sprite,
    game->r_to[tower(defender->cursor.t_to)]);
    sfSprite_setScale(obj->sprite, obj->resize);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f)
    {game->r_to[tower(defender->cursor.t_to)].width / 2,
    game->r_to[tower(defender->cursor.t_to)].height / 2});
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}

void add_monkey(game_t *game, defender_t *defender, sfVector2f pos)
{
    monkey_t *obj = malloc(sizeof(monkey_t));
    monkey_t *last = game->monkey;
    while (last->next != NULL) last = last->next;
    obj->prev = last;
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->resize = (sfVector2f) {0.75, 0.75};
    add_icons(game, defender, obj);
    sfSprite_setScale(obj->sprite, obj->resize);
    sfSprite_setTexture(obj->sprite, game->t_monkey, sfTrue);
    sfSprite_setTextureRect(obj->sprite,
    game->r_to[tower(defender->cursor.t_to)]);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f)
    {game->r_to[tower(defender->cursor.t_to)].width / 2,
    game->r_to[tower(defender->cursor.t_to)].height / 2});
    obj->next = NULL;
    last->next = obj;
}

void tower_node(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    if (game->monkey_head == NULL) {
        game->monkey = first_monkey(game, defender,
        (sfVector2f) {defender->cursor.pos.x, defender->cursor.pos.y});
        game->monkey_head = game->monkey;
    } else {
        add_monkey(game, defender,
        (sfVector2f) {defender->cursor.pos.x, defender->cursor.pos.y});
    }
}
