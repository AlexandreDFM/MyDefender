/*
** EPITECH PROJECT, 2022
** monkey
** File description:
** Functions about monkeys
*/

#include "my_defender.h"

monkey_t c_monkey(sfVector2f pos, sfIntRect hitbox, sfVector2f size, int type)
{
    monkey_t monkey;
    monkey.sprite = sfSprite_create();
    monkey.texture = sfTexture_createFromFile("./sprites/monkey.png", NULL);
    monkey.pos = pos;
    monkey.hitbox = hitbox;
    monkey.resize = size;
    sfSprite_setTexture(monkey.sprite, monkey.texture, sfTrue);
    sfSprite_setPosition(monkey.sprite, monkey.pos);
    sfSprite_setScale(monkey.sprite, monkey.resize);
    sfSprite_setTextureRect(monkey.sprite, monkey.hitbox);
    return monkey;
}

void display_monkey(sfRenderWindow *w, monkey_t monkey)
{
    sfSprite_setTexture(monkey.sprite, monkey.texture, sfTrue);
    sfSprite_setPosition(monkey.sprite, monkey.pos);
    sfSprite_setTextureRect(monkey.sprite, monkey.hitbox);
    sfSprite_setScale(monkey.sprite, monkey.resize);
    sfRenderWindow_drawSprite(w, monkey.sprite, NULL);
}

void check_m_pos(game_t *game, monkey_t monkey)
{
    unsigned long long int coords = ((game->bloon->pos.x + (game->bloon->dir.x * - 1) * 50) * 4) + ((game->bloon->pos.y + (game->bloon->dir.y * - 1) * 50) * 4 * 1920);
    if (coords >= 0 && coords <= 2147483647) {
        sfVector3f color = (sfVector3f) {game->pixels[coords], game->pixels[coords + 1], game->pixels[coords + 2]};
        for (int i = 0; i < 4; i++) {
            if (color.x == game->colors[i].x && color.y == game->colors[i].y && color.z == game->colors[i].z) {
                game->bloon->dir = game->dirs[i];
            }
        }
    }
}

void add_monkey(game_t *game)
{
    monkey_t *obj = malloc(sizeof(monkey_t));
    monkey_t *last = game->bloon;
    while (last->next != NULL) last = last->next;
    obj->prev = last;
    obj->sprite = sfSprite_create();
    obj->pos = (sfVector2f) {last->pos.x, last->pos.y - 30};
    sfSprite_setTexture(obj->sprite, game->t_array[2], sfTrue);
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {21, 27});
    // sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 42, 54});
    // obj->dir = game->bloon->dir;
    obj->next = NULL;
    last->next = obj;
}

monkey_t *first_monkey(game_t *game)
{
    monkey_t *obj = malloc(sizeof(monkey_t));
    char **positions = my_strtwa(get_lines("maps/map1"), ":\n");
    obj->sprite = sfSprite_create();
    obj->pos = (sfVector2f) {my_atoi(positions[1]), my_atoi(positions[2])};
    sfSprite_setTexture(obj->sprite, game->t_array[2], sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {21, 27});
    sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 42, 54});
    // obj->dir = (sfVector2f) {my_atoi(positions[7]), my_atoi(positions[8])};
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}
