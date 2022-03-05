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
    monkey.texture = sfTexture_createFromFile("./sprites/all_monkey.png", NULL);
    monkey.pos = pos;
    monkey.hitbox = hitbox;
    monkey.resize = size;
    sfSprite_setTexture(monkey.sprite, monkey.texture, sfTrue);
    sfSprite_setPosition(monkey.sprite, monkey.pos);
    sfSprite_setOrigin(monkey.sprite, (sfVector2f) {monkey.hitbox.width / 2, monkey.hitbox.height / 2});
    sfSprite_setScale(monkey.sprite, monkey.resize);
    sfSprite_setTextureRect(monkey.sprite, monkey.hitbox);
    return monkey;
}

c_hb_t c_monkey_c(sfVector2f pos, float radius, sfVector2f size, sfColor color)
{
    c_hb_t monkey_c;
    monkey_c.shape = sfCircleShape_create();
    monkey_c.radius = radius;
    monkey_c.color = (sfColor) {255, 0, 0, 120};
    monkey_c.pos = pos;
    sfCircleShape_setFillColor(monkey_c.shape, monkey_c.color);
    sfCircleShape_setRadius(monkey_c.shape, radius);
    sfCircleShape_setPosition(monkey_c.shape, monkey_c.pos);
    return monkey_c;
}

void display_monkey(sfRenderWindow *w, monkey_t monkey)
{
    sfSprite_setTexture(monkey.sprite, monkey.texture, sfTrue);
    sfSprite_setPosition(monkey.sprite, monkey.pos);
    sfSprite_setTextureRect(monkey.sprite, monkey.hitbox);
    sfSprite_setOrigin(monkey.sprite, (sfVector2f) {monkey.hitbox.width / 2, monkey.hitbox.height / 2});
    sfSprite_setScale(monkey.sprite, monkey.resize);
    sfRenderWindow_drawSprite(w, monkey.sprite, NULL);
}

void display_monkey_hb(sfRenderWindow *w, c_hb_t hb_monkey)
{
    sfCircleShape_setFillColor(hb_monkey.shape, hb_monkey.color);
    sfCircleShape_setPosition(hb_monkey.shape, hb_monkey.pos);
    sfCircleShape_setOrigin(hb_monkey.shape, (sfVector2f) {hb_monkey.radius, hb_monkey.radius});
    sfRenderWindow_drawCircleShape(w, hb_monkey.shape, NULL);
}

int check_m_pos(game_t *game, defender_t *defender)
{
    int m = (defender->cursor.pos.x * 4) + (defender->cursor.pos.y * 4 * 1920);
    int a1 = ((defender->cursor.pos.x - game->rect_monkeys[modeValid(defender->cursor.s_monkey)].width / 2 * 16 / 100) * 4) + ((defender->cursor.pos.y - game->rect_monkeys[modeValid(defender->cursor.s_monkey)].height / 2) * 4 * 1920);
    int a2 = ((defender->cursor.pos.x  + game->rect_monkeys[modeValid(defender->cursor.s_monkey)].width / 2 * 16 / 100) * 4) + ((defender->cursor.pos.y - game->rect_monkeys[modeValid(defender->cursor.s_monkey)].height / 2) * 4 * 1920);
    int b1 = ((defender->cursor.pos.x - game->rect_monkeys[modeValid(defender->cursor.s_monkey)].width / 2 * 16 / 100) * 4) + ((defender->cursor.pos.y + game->rect_monkeys[modeValid(defender->cursor.s_monkey)].height / 2 * 1 / 100) * 4 * 1920);
    int b2 = ((defender->cursor.pos.x + game->rect_monkeys[modeValid(defender->cursor.s_monkey)].width / 2 * 16 / 100)* 4) + ((defender->cursor.pos.y + game->rect_monkeys[modeValid(defender->cursor.s_monkey)].height / 2 * 1 / 100) * 4 * 1920);
    //my_printf("%d %d %d %d %d\n", (m / 2) / 2, (a1 / 2) / 2, (a2 / 2) / 2, (b1 / 2) / 2, (b2 / 2) / 2);
    if (m <= 0 && m >= 2147483647) return 0;
    if (a1 <= 0 && a1 >= 2147483647) return 0;
    if (a2 <= 0 && a2 >= 2147483647) return 0;
    if (b1 <= 0 && b1 >= 2147483647) return 0;
    if (b2 <= 0 && b2 >= 2147483647) return 0;
    sfVector3f color_m = (sfVector3f) {game->pixels[m], game->pixels[m + 1], game->pixels[m + 2]};
    sfVector3f color_a1 = (sfVector3f) {game->pixels[a1], game->pixels[a1 + 1], game->pixels[a1 + 2]};
    sfVector3f color_a2 = (sfVector3f) {game->pixels[a2], game->pixels[a2 + 1], game->pixels[a2 + 2]};
    sfVector3f color_b1 = (sfVector3f) {game->pixels[b1], game->pixels[b1 + 1], game->pixels[b1 + 2]};
    sfVector3f color_b2 = (sfVector3f) {game->pixels[b2], game->pixels[b2 + 1], game->pixels[b2 + 2]};
    if (color_m.x != 0 || color_m.y != 0 || color_m.z != 0) return 0;
    if (color_a1.x != 0 || color_a1.y != 0 || color_a1.z != 0) return 0;
    if (color_a2.x != 0 || color_a2.y != 0 || color_a2.z != 0) return 0;
    if (color_b1.x != 0 || color_b1.y != 0 || color_b1.z != 0) return 0;
    if (color_b2.x != 0 || color_b2.y != 0 || color_b2.z != 0) return 0;
    return 1;
}

void fill_tower_box(game_t *game)
{
    int x_first = 1508;
    int y_first = 200;
    sfFloatRect **tower_box = malloc(sizeof(sfFloatRect *) * 8);
    tower_box[7] = NULL;
    for (int i = 0; i < 7; i++) {
        tower_box[i] = malloc(sizeof(sfFloatRect) * 2);
        for (int j = 0; j < 2; j++, x_first += 88) {
            tower_box[i][j] = (sfFloatRect) {x_first, y_first, 113 * 0.7017543859649123, 93 * 0.7017543859649123};
        }
        y_first += 87;
        x_first = 1508;
        if (i == 5)
            y_first += 81;
    }
    game->tower_box = tower_box;
}

void fill_debug_t_box(game_t *game)
{
    for (int i = 0, nb = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++, nb++) {
            game->tower_hitbox[nb].shape = sfRectangleShape_create();
            game->tower_hitbox[nb].rect = (sfIntRect) {0, 0, (int) game->tower_box[i][j].width, (int) game->tower_box[i][j].height};
            game->tower_hitbox[nb].color = (sfColor) {255, 0, 0, 100};
            game->tower_hitbox[nb].pos = (sfVector2f) {game->tower_box[i][j].left, game->tower_box[i][j].top};
            sfRectangleShape_setFillColor(game->tower_hitbox[nb].shape, game->tower_hitbox[nb].color);
            sfRectangleShape_setSize(game->tower_hitbox[nb].shape, (sfVector2f) {game->tower_hitbox[nb].rect.width, game->tower_hitbox[nb].rect.height});
            sfRectangleShape_setPosition(game->tower_hitbox[nb].shape, game->tower_hitbox[nb].pos);
        }
    }
}

void fill_rect_monkeys(game_t *game)
{
    char **rects = my_strtwa(get_lines("./parsing/rect_monkeys.txt"), "\n");
    char **temp_rect = NULL;
    int size_array = 0;
    for (;rects[size_array] != NULL; size_array++);
    sfIntRect *rect_monkeys = malloc(sizeof(sfIntRect) * size_array);
    for (int i = 0; i < size_array - 1; i++) {
        temp_rect = my_strtwa(rects[i], "|");
        rect_monkeys[i] = (sfIntRect) {my_atoi(temp_rect[0]), my_atoi(temp_rect[1]), my_atoi(temp_rect[2]), my_atoi(temp_rect[3])};
        temp_rect = NULL;
    }
    free(rects);
    free(temp_rect);
    game->rect_monkeys = rect_monkeys;
}

int modeValid(int mode)
{
    switch (mode) {
        case DART_MONKEY :
            return 0;
        case TACK_SHOOTER :
            return 1;
        case NINJA_MONKEY :
            return 2;
        case BOMB_SHOOTER :
            return 3;
        case ICE_MONKEY :
            return 4;
        case GLUE_GUNNER :
            return 5;
        case SUPER_MONKEY :
            return 6;
    };
    return 84;
}

monkey_t *first_monkey(game_t *game, defender_t *defender, sfVector2f pos)
{
    monkey_t *obj = malloc(sizeof(monkey_t));
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->resize = (sfVector2f) {0.75, 0.75};
    sfSprite_setTexture(obj->sprite, game->t_monkey, sfTrue);
    sfSprite_setTextureRect(obj->sprite, game->rect_monkeys[modeValid(defender->cursor.s_monkey)]);
    sfSprite_setScale(obj->sprite, obj->resize);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {game->rect_monkeys[modeValid(defender->cursor.s_monkey)].width / 2, game->rect_monkeys[modeValid(defender->cursor.s_monkey)].height / 2});
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
    sfSprite_setScale(obj->sprite, obj->resize);
    sfSprite_setTexture(obj->sprite, game->t_monkey, sfTrue);
    sfSprite_setTextureRect(obj->sprite, game->rect_monkeys[modeValid(defender->cursor.s_monkey)]);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {game->rect_monkeys[modeValid(defender->cursor.s_monkey)].width / 2, game->rect_monkeys[modeValid(defender->cursor.s_monkey)].height / 2});
    obj->next = NULL;
    last->next = obj;
}

void pos_monkey(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    if (game->monkey_head == NULL) {
        game->monkey = first_monkey(game, defender, (sfVector2f) {defender->cursor.pos.x, defender->cursor.pos.y});
        game->monkey_head = game->monkey;
    } else {
        add_monkey(game, defender, (sfVector2f) {defender->cursor.pos.x, defender->cursor.pos.y});
    }
}

void check_t_hb(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    for (int y = 0, monkey = 1; y < 7; y++) {
        for (int x = 0; x < 2; x++, monkey++) {
            if (sfFloatRect_contains(&game->tower_box[y][x], defender->cursor.pos.x, defender->cursor.pos.y) && defender->event.mouseButton.type == sfEvtMouseButtonReleased && defender->event.mouseButton.button == sfMouseLeft) {
                if (modeValid(monkey) != 84) {
                    defender->cursor.s_monkey = monkey;
                    defender->cursor.monkey.hitbox = game->rect_monkeys[modeValid(monkey)];
                }
            } else if (defender->cursor.s_monkey != NO_MONKEY && defender->event.mouseButton.type == sfEvtMouseButtonPressed && defender->event.mouseButton.button == sfMouseLeft) {
                if (check_m_pos(game, defender)) pos_monkey(w, game, defender);
                defender->cursor.s_monkey = NO_MONKEY;
            }
        }
    }
}

void display_tower_hitbox(sfRenderWindow *w, game_t *game, defender_t *defender)
{
    for (int i = 0; i < 14; i++) {
        sfRenderWindow_drawRectangleShape(w, game->tower_hitbox[i].shape, NULL);
    }
    check_t_hb(w, game, defender);
}
