/*
** EPITECH PROJECT, 2022
** init
** File description:
** Function to init game
*/

#include "my_defender.h"

void init_textures5(game_t *game)
{
    game->waves = init_waves();
    game->b_colors = "RBGYW";
    fill_waves(game);
    game->bloon = game->head;
    game->font = sfFont_createFromFile("font/font.ttf");
    game->money = 650;
    game->health = 1;
    game->c = sfClock_create();
    game->h = sfText_create();
    game->h = create_text(game->font, (sfVector2f) {1570, 93}, "0", 48);
    game->sc = create_text(game->font, (sfVector2f) {1570, 38}, "0", 48);
    sfText_setFillColor(game->h, sfRed);
    game->wav = create_text(game->font, (sfVector2f) {1510, 850}, "0", 48);
    sfText_setStyle(game->wav, 1);
}

void init_textures4(game_t *game)
{
    game->pixels = malloc(sizeof(sfUint8 *));
    game->pixels = sfImage_getPixelsPtr(game->map_c);
    game->bloon = load_bloons(game);
    game->head = game->bloon;
    sfVector3f colors[5] = {{0, 51, 255}, {0, 255, 72},
    {197, 0, 0}, {158, 0, 197}, {255, 106, 0}};
    sfVector2f dirs[5] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}, {0, 0}};
    game->colors = malloc(sizeof(sfVector3f) * 6);
    game->dirs = malloc(sizeof(sfVector2f) * 6);
    for (int i = 0; i < 5; i++) {
        game->colors[i] = colors[i];
        game->dirs[i] = dirs[i];
    }
    game->frame = (sfFloatRect) {237, 0, 1359, 970};
    game->wave_nb = 0;
    game->wave_ind = 0;
    game->ff = 1;
    init_textures5(game);
}

void init_textures3(game_t *game)
{
    sfSprite_setTexture(game->hud, game->t_array[0], sfTrue);
    sfSprite_setTexture(game->map, game->t_array[1], sfTrue);
    sfSprite_setTexture(game->up_gui, game->t_array[5], sfTrue);
    sfSprite_setPosition(game->map, (sfVector2f) {237, 0});
    sfSprite_setPosition(game->up_gui, (sfVector2f) {242, 858});
    sfSprite_setScale(game->map, (sfVector2f) {1.259, 1.242857142857143});
    sfSprite_setScale(game->hud, (sfVector2f) {0.7017543859649123,
    0.668181818182});
    sfSprite_setScale(game->up_gui, (sfVector2f) {0.7017543859649123,
    0.668181818182});
    game->map_c = sfImage_createFromFile("maps/map_test.png");
    init_textures4(game);
}

void init_textures2(game_t *game)
{
    game->hud = sfSprite_create();
    game->map = sfSprite_create();
    game->up_gui = sfSprite_create();
    for (int i = 0; i < 2; i++) {
        game->p_but[i].sprite = sfSprite_create();
        game->p_but[i].rect = (sfIntRect) {i * 126 * 3, 0, 126, 127};
        game->p_but[i].resize = (sfVector2f) { 0.5, 0.5};
        game->p_but[i].pos = (sfVector2f) {1540 + 90 * i, 945};
        game->p_but[i].clicked = 0;
        sfSprite_setTexture(game->p_but[i].sprite, game->t_array[6], sfTrue);
        sfSprite_setTextureRect(game->p_but[i].sprite, game->p_but[i].rect);
        sfSprite_setScale(game->p_but[i].sprite, game->p_but[i].resize);
        sfSprite_setPosition(game->p_but[i].sprite, game->p_but[i].pos);
        sfSprite_setOrigin(game->p_but[i].sprite,
        (sfVector2f) {126 / 2, 127 / 2});
    }
    init_textures3(game);
}

void init_textures(game_t *g)
{
    g->cleared = 0;
    int i = 0;
    char **array = my_strtwa(get_lines("sprites/textures.txt"), "\n");
    for (; array[i] != 0; i++);
    sfTexture **t_array = malloc(sizeof(sfTexture *) * (i + 1));
    for (int j = 0; j < i - 1; j++)
        t_array[j] = sfTexture_createFromFile(array[j], NULL);
    g->t_array = t_array;
    my_free_array(array);
    g->tower_stats = my_strtwa(get_lines("./parsing/tower_stats.txt"), "\n");
    g->monkey = NULL;
    g->monkey_head = NULL;
    g->t_monkey = sfTexture_createFromFile("./sprites/all_monkey.png", NULL);
    fill_hudtowers(g);
    fill_r_to(g);
    g->gameoverscreen = c_r_hitbox((sfVector2f) {0, 0}, (sfIntRect)
    {0, 0, 1920, 1029}, (sfVector2f) {1, 1}, (sfColor) {0, 0, 0, 100});
    init_textures2(g);
}
