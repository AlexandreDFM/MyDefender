/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

sfVector2f set_pos(int i, int offset)
{
    switch (i)
    {
    case 0: case 1: case 2: case 3: case 4:
        return (sfVector2f) {518 + offset * i, 384};
    case 5: case 6: case 7:
        return (sfVector2f) {618 + offset * (i - 4.5), 534};
    }
    return (sfVector2f) {0, 0};
}

defender_t init3(defender_t defender)
{
    int indx = 0, indy = 127;
    int offset = 200;
    sfTexture *texture = sfTexture_createFromFile("sprites/game_button.png", NULL);
    for (int i = 0; i < 8; i++) {
        defender.p_menu.pause_b[i].texture = texture;
        defender.p_menu.pause_b[i].sprite = sfSprite_create();
        sfSprite_setTexture(defender.p_menu.pause_b[i].sprite, texture, sfTrue);
        sfSprite_setOrigin(defender.p_menu.pause_b[i].sprite, (sfVector2f) {63, 63.5});
        defender.p_menu.pause_b[i].pos = set_pos(i, offset);
        if (i < 4)
            defender.p_menu.pause_b[i].rect = (sfIntRect) {0 + 126 * i, 127, 126, 127};
        else if (i == 4) {
            defender.p_menu.pause_b[i].rect = (sfIntRect) {126 + indx, 127 + indy, 126, 127};
            indx += 252;
        } else {
            defender.p_menu.pause_b[i].rect = (sfIntRect) {0 + indx, 127 + indy, 126, 127};
            indx += 252;
        }
        if (i == 5) indx = 0, indy += 127;
        sfSprite_setPosition(defender.p_menu.pause_b[i].sprite, defender.p_menu.pause_b[i].pos);
        sfSprite_setTextureRect(defender.p_menu.pause_b[i].sprite, defender.p_menu.pause_b[i].rect);
    }
    return defender;
}

defender_t init2(defender_t defender)
{
    defender.p_menu.fade = sfRectangleShape_create();
    sfRectangleShape_setSize(defender.p_menu.fade, (sfVector2f) {1442, 1080});
    sfRectangleShape_setPosition(defender.p_menu.fade, (sfVector2f) {237, 0});
    defender.p_menu.color = sfColor_fromRGBA(0, 0, 0, 128);
    sfRectangleShape_setFillColor(defender.p_menu.fade, defender.p_menu.color);
    return init3(defender);
}

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
    defender.playing = 0;
    defender.state = 0;
    defender.aplay = 0;
    return init2(defender);
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
    game.tower_stats = my_strtwa(get_lines("./parsing/tower_stats.txt"), "\n");
    game.hud = sfSprite_create();
    game.map = sfSprite_create();
    game.up_gui = sfSprite_create();
    for (int i = 0; i < 2; i++) {
        game.p_but[i].sprite = sfSprite_create();
        game.p_but[i].rect = (sfIntRect) {i * 126 * 3, 0, 126, 127};
        game.p_but[i].resize = (sfVector2f) { 0.5, 0.5};
        game.p_but[i].pos = (sfVector2f) {1540 + 90 * i, 945};
        game.p_but[i].clicked = 0;
        sfSprite_setTexture(game.p_but[i].sprite,t_array[6], sfTrue);
        sfSprite_setTextureRect(game.p_but[i].sprite, game.p_but[i].rect);
        sfSprite_setScale(game.p_but[i].sprite, game.p_but[i].resize);
        sfSprite_setPosition(game.p_but[i].sprite, game.p_but[i].pos);
        sfSprite_setOrigin(game.p_but[i].sprite, (sfVector2f) {126 / 2, 127 / 2});
    }
    sfSprite_setTexture(game.hud, t_array[0], sfTrue);
    sfSprite_setTexture(game.map, t_array[1], sfTrue);
    sfSprite_setTexture(game.up_gui, t_array[5], sfTrue);
    sfSprite_setPosition(game.map, (sfVector2f) {237, 0});
    sfSprite_setPosition(game.up_gui, (sfVector2f) {242, 900});
    sfSprite_setScale(game.map, (sfVector2f) {1.259, 1.242857142857143});
    sfSprite_setScale(game.hud, (sfVector2f) {0.7017543859649123, 0.7012987012987013});
    sfSprite_setScale(game.up_gui, (sfVector2f) {0.7017543859649123, 0.7012987012987013});
    game.map_c = sfImage_createFromFile("maps/map_test.png");
    game.pixels = malloc(sizeof(sfUint8 *));
    game.pixels = sfImage_getPixelsPtr(game.map_c);
    game.bloon = load_bloons(&game);
    game.head = game.bloon;
    sfVector3f colors[5] = {{0, 51, 255}, {0, 255, 72},
    {197, 0, 0}, {158, 0, 197}, {255, 106, 0}};
    sfVector2f dirs[5] = {{0,1}, {-1, 0}, {1, 0}, {0, -1}, {0, 0}};
    game.colors = malloc(sizeof(sfVector3f) * 6);
    game.dirs = malloc(sizeof(sfVector2f) * 6);
    for (int i = 0; i < 5; i++) {
        game.colors[i] = colors[i];
        game.dirs[i] = dirs[i];
    }
    game.frame = (sfFloatRect) {237, 0, 1359, 970};
    game.wave_nb = 1;
    game.wave_ind = 0;
    game.ff = 1;
    game.waves = init_waves();
    game.b_colors = "RBGYW";
    fill_waves(&game);
    game.bloon = game.head;
    game.font = sfFont_createFromFile("sprites/font.ttf");
    game.score = 0;
    game.health = 100;
    game.c = sfClock_create();
    game.h = sfText_create();
    game.sc = sfText_create();
    game.wav = sfText_create();
    sfText_setFillColor(game.h, sfRed);
    sfText_setFont(game.h, game.font);
    sfText_setFont(game.sc, game.font);
    sfText_setFont(game.wav, game.font);
    sfText_setPosition(game.sc, (sfVector2f) {1570, 38});
    sfText_setPosition(game.h, (sfVector2f) {1570, 93});
    sfText_setCharacterSize(game.sc, 48);
    sfText_setCharacterSize(game.h, 48);
    game.monkey = NULL;
    game.monkey_head = NULL;
    game.t_monkey = sfTexture_createFromFile("./sprites/all_monkey.png", NULL);
    fill_hudtowers(&game);
    fill_r_to(&game);
    return game;
}
