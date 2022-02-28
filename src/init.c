/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

defender_t init(void)
{
    defender_t defender;
    defender.intro = create_go("./sprites/ninja.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 383, 204}, (sfVector2f) {5, 5});
    defender.menu = create_go("./sprites/back_menu.png", (sfVector2f) {-84,0},
    (sfIntRect) {0, 0, 720, 360}, (sfVector2f) {2.9, 2.9});
    defender.title = create_go("./sprites/bloons_logo.png",
    (sfVector2f) {769.5, 10},(sfIntRect) {0, 0, 796, 612},
    (sfVector2f) {0.5, 0.5});
    for (int i = 0, posy = 400, rectl = 0 ; i < 4;
    i++, posy += 106, rectl += 43)
        defender.bouton[i] = create_bouton("./sprites/menu_buttons.png",
        (sfVector2f) {805, posy}, (sfIntRect) {0, rectl, 159, 43});
    defender.cursor = create_cursor("./sprites/cursor.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 64, 64});
    defender.clockintro = sfClock_create();
    defender.scene = GAME;
    return defender;
}

game_t init_textures(void)
{
    game_t game;
    int i = 0;
    char **array = my_strtwa(get_lines("sprites/textures.txt"), "\n");
    for (; array[i] != 0; i++);
    sfTexture **t_array = malloc(sizeof(sfTexture *) * (i + 1));
    for (int j = 0; j < i - 1; j++)
        t_array[j] = sfTexture_createFromFile(array[j], NULL);
    game.t_array = t_array;
    game.hud = sfSprite_create();
    game.map = sfSprite_create();
    sfSprite_setTexture(game.hud, t_array[0], sfTrue);
    sfSprite_setTexture(game.map, t_array[1], sfTrue);
    sfSprite_setPosition(game.map, (sfVector2f) {237, 0});
    sfSprite_setScale(game.map, (sfVector2f) {1.259, 1.242857142857143});
    game.map_c = sfImage_createFromFile("maps/map_test.png");
    game.pixels = malloc(sizeof(sfUint8 *));
    game.pixels = sfImage_getPixelsPtr(game.map_c);
    game.bloon = load_bloons(&game);
    game.head = game.bloon;
    sfVector3f colors[5] = {{0, 51, 255}, {0, 255, 72},
    {197, 0, 0}, {158, 0, 197}, {255, 106, 0}};
    sfVector2f dirs[5] = {{0,1}, {-1, 0}, {1, 0}, {0, -1}, {}};
    game.colors = malloc(sizeof(sfVector3f) * 6);
    game.dirs = malloc(sizeof(sfVector2f) * 6);
    for (int i = 0; i < 5; i++) {
        game.colors[i] = colors[i];
        game.dirs[i] = dirs[i];
    }
    game.frame = (sfFloatRect) {237, 0, 1359, 970};
    game.wave_nb = 1;
    game.wave_ind = 0;
    game.waves = init_waves();
    game.b_colors = "RBGYW";
    fill_waves(&game);
    game.bloon = game.head;
    return game;
}
