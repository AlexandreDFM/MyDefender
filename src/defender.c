/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Principale file of defender project
*/

#include "my_defender.h"

void intro(sfRenderWindow *window, defender_t *defender)
{
    display_intro(window, defender->intro);
}

void close_window(sfRenderWindow *window, defender_t *defender)
{
    if (defender->event.type == sfEvtClosed ||
    (defender->event.type == sfEvtKeyPressed &&
    defender->event.key.code == sfKeyRShift)) {
        sfRenderWindow_close(window);
    }
}

void check_events(sfRenderWindow *window, defender_t *defender)
{
    close_window(window, defender);
}

void move_rectintro(defender_t *defender, sfIntRect *rect, int modify, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = modify;
        defender->scene = MENU;
    } else {
        rect->left += modify;
    }
}

void first_clock(defender_t *defender)
{
    if (sfClock_getElapsedTime(defender->clockintro).microseconds > 100000.0) {
        move_rectintro(defender, &defender->intro.rect, 383, 12256);
        sfClock_restart(defender->clockintro);
    }
}

void boucle(sfRenderWindow *window, defender_t *defender, game_t *game_s)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &defender->event)) {
            check_events(window, defender);
        }
        if (defender->scene == MENU) {
            menu(window, defender);
        }
        if (defender->scene == GAME) {
            game(window, game_s);
        }
        display_cursor(window, defender->cursor);
        if (defender->scene == INTRO) {
            first_clock(defender);
            intro(window, defender);
        }sfRenderWindow_display(window);
    }
}

defender_t init(void)
{
    defender_t defender;
    defender.intro = create_intro("./sprites/ninja.png", (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 383, 204});
    defender.menu = create_menu("./sprites/back_menu.png", (sfVector2f) {-84,0}, (sfIntRect) {0, 0, 720, 360});
    defender.title = create_title("./sprites/bloons_logo.png", (sfVector2f) {769.5, 10}, (sfIntRect) {0, 0, 796, 612});
    defender.bouton[0] = create_bouton("./sprites/menu_buttons.png", (sfVector2f) {805, 400 + 0}, (sfIntRect) {0, 0, 159, 43});
    defender.bouton[1] = create_bouton("./sprites/menu_buttons.png", (sfVector2f) {805, 400 + 53 * 2}, (sfIntRect) {0, 43, 159, 43});
    defender.bouton[2] = create_bouton("./sprites/menu_buttons.png", (sfVector2f) {805, 400 + 106 * 2}, (sfIntRect) {0, 86, 159, 43});
    defender.bouton[3] = create_bouton("./sprites/menu_buttons.png", (sfVector2f) {805, 400 + 159 * 2}, (sfIntRect) {0, 129, 159, 43});
    defender.cursor = create_cursor("./sprites/cursor.png", (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 64, 64});
    defender.clockintro = sfClock_create();
    defender.scene = GAME;
    return defender;
}

game_t init_textures(void)
{
    game_t game;
    int i = 0;
    char **array = my_str_to_word_array(get_lines("sprites/textures.txt"));
    for (; array[i] != 0; i++);
    sfTexture **t_array = malloc(sizeof(sfTexture *) * (i + 1));
    for (int j = 0; j < i - 1; j++) {
        t_array[j] = sfTexture_createFromFile(array[j], NULL);
    }
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
    for (int i = 0; i < 100; i++) {
        fill_bloons(&game);
    }
    game.bloon = game.head;
    sfVector3f colors[4] = {{0, 51, 255}, {0, 255, 72}, {197, 0, 0}, {158, 0, 197}};
    sfVector2f dirs[4] = {{0,1}, {-1, 0}, {1, 0}, {0, -1}};
    game.colors = malloc(sizeof(sfVector3f) * 5);
    game.dirs = malloc(sizeof(sfVector2f) * 5);
    for (int i = 0; i < 4; i++) {
        game.colors[i] = colors[i];
        game.dirs[i] = dirs[i];
    }
    game.frame = (sfFloatRect) {237, 0, 1259, 870};
    return game;
}


game_t init_waves(void)
{
    int i = 1, wave = 0, j = 0;
    int count = 1;
    char **tmp = my_str_to_word_array(get_lines("maps/wave"));
    for (; tmp[i] != NULL; i++);
    char ***waves = malloc(sizeof(char **) * i);
    my_memset(waves, 0, i);
    for (; tmp[j] != 0; j++) {
        for (int index = 0; tmp[j][index] != '\0'; index++) {
            if (tmp[j][index] == '|') count++;
        }
        waves[wave] = malloc(sizeof(char *) * count);
        if (my_strcmp(tmp[j], "\n") == 0) wave++;
        waves[wave][j] = my_strdup(tmp[j]);
    }
    waves[wave] = 0;
}

void load_window()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    defender_t defender = init();
    game_t game = init_textures();
    init_waves();
    char *name = "My_defender Project";
    window = sfRenderWindow_create(mode, name, sfFullscreen | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 300);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    boucle(window, &defender, &game);
}
