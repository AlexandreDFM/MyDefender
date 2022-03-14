/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Principale file of defender project
*/

#include "my_defender.h"

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
    if (defender->scene == INTRO && defender->event.type == sfEvtKeyPressed)
        defender->scene = MENU;
    if (defender->state == 1 && defender->event.type == sfEvtKeyReleased &&
    defender->event.key.code == sfMouseLeft) {
        defender->state = 0;
    }
}

void boucle(sfRenderWindow *window, defender_t *defender, game_t *game_s)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &defender->event)) {
            check_events(window, defender);
        }
        if (defender->scene == MENU)
            menu(window, defender);
        if (defender->scene == SETTINGS)
            settings(window, defender);
        if (defender->scene == HOW_TO_PLAY)
            how_to_play(window, defender);
        if (defender->scene == GAME)
            game(window, game_s, defender);
        if (defender->scene == PAUSE)
            pause_f(window, defender, game_s);
        display_cursor(window, game_s, defender, defender->cursor);
        if (defender->scene == INTRO)
            intro(window, defender);
        sfRenderWindow_display(window);
    }
}

void load_window()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    defender_t defender = init();
    game_t game = init_textures();
    char *name = "My_defender Project";
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 300);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    boucle(window, &defender, &game);
}
