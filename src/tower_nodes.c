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
    obj->radius = my_atoi(stats[5]);
    obj->damage = my_atoi(stats[6]);
    obj->attackspeed = my_atoi(stats[7]);
    obj->clockattack = sfClock_create();
    obj->blooncibled = NULL;
    obj->range = c_monkey_c(obj->pos, obj->radius, (sfVector2f) {0.75, 0.75}, (sfColor) {0, 0, 0, 120});
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
    obj->hitbox_sell.shape = sfRectangleShape_create();
    obj->hitbox_sell.rect = (sfIntRect) {0, 0, 165, 45};
    obj->hitbox_sell.color = (sfColor) {0, 0, 255, 100};
    obj->hitbox_sell.pos = (sfVector2f) {610, 950};
    sfRectangleShape_setFillColor(obj->hitbox_sell.shape, obj->hitbox_sell.color);
    sfRectangleShape_setSize(obj->hitbox_sell.shape, (sfVector2f) {obj->hitbox_sell.rect.width, obj->hitbox_sell.rect.height});
    sfRectangleShape_setPosition(obj->hitbox_sell.shape, obj->hitbox_sell.pos);
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

void delete_tower(game_t *game)
{
    if (game->monkey == NULL) return;
    if (game->monkey == game->monkey_head) game->monkey_head = NULL;
    if (game->monkey->next != NULL) game->monkey->next->prev = game->monkey->prev;
    if (game->monkey->prev != NULL) game->monkey->prev->next = game->monkey->next;
    game->monkey = game->monkey->next;
}

void tower_node(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    if (game->monkey_head == NULL) {
        game->monkey = first_monkey(game, defender,
        (sfVector2f) {defender->cursor.pos.x, defender->cursor.pos.y});
        game->monkey_head = game->monkey;
        sfSound_play(defender->towerpl);
    } else {
        add_monkey(game, defender,
        (sfVector2f) {defender->cursor.pos.x, defender->cursor.pos.y});
        sfSound_play(defender->towerpl);
    }
}
