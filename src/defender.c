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
    defender->event.mouseButton.button == sfMouseLeft) {
        defender->state = 0;
    }
}

void switch_display(sfRenderWindow *w, defender_t *defender, game_t *game_s)
{
    if (defender->scene == MENU) menu(w, defender, game_s);
    if (defender->scene == SETTINGS) settings(w, defender);
    if (defender->scene == HOW_TO_PLAY) how_to_play(w, defender);
    if (defender->scene == MAP_SELECT) select_map(w, defender, game_s);
    if (defender->scene == GAME) game(w, game_s, defender);
    if (defender->scene == PAUSE) pause_f(w, defender, game_s);
    if (defender->scene == GAMEWIN) game_win(w, defender, game_s);
    if (defender->scene == GAMEOVER) game_over(w, defender, game_s);
    d_cursor(w, game_s, defender, defender->cursor);
    if (defender->scene == INTRO)
        intro(w, defender);
}

void boucle(sfRenderWindow *window, defender_t *defender, game_t *game_s)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &defender->event)) {
            check_events(window, defender);
        }
        switch_display(window, defender, game_s);
        sfRenderWindow_display(window);
    }
}

void load_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    defender_t defender = init();
    game_t game;
    game.cleared = 1;
    char *name = "My_defender Project";
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    boucle(window, &defender, &game);
    all_uninit(&defender, &game);
}
