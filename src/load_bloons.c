/*
** EPITECH PROJECT, 2022
** load
** File description:
** load
*/

#include "my_defender.h"

bloons_t load_bloons(game_t *game)
{
    bloons_t obj;
    char **positions = my_str_to_word_array(get_lines("maps/map1"));
    obj.sprite = sfSprite_create();
    obj.pos = (sfVector2f) {my_atoi(positions[1]), my_atoi(positions[2])};
    sfSprite_setTexture(obj.sprite, game->t_array[2], sfTrue);
    sfSprite_setPosition(obj.sprite, obj.pos);
    sfSprite_setOrigin(obj.sprite, (sfVector2f) {21, 27});
    sfSprite_setTextureRect(obj.sprite, (sfIntRect) {0, 0, 42, 54});
    obj.dir = (sfVector2f) {my_atoi(positions[7]), my_atoi(positions[8])};
    return obj;
}
