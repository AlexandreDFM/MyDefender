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
    defender->event.key.code == sfKeyBackspace)) {
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

void boucle(sfRenderWindow *window, defender_t *defender)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &defender->event)) {
            check_events(window, defender);
        }
        if (defender->scene == INTRO) {
            first_clock(defender);
            intro(window, defender);
        }
        if (defender->scene == MENU) {
            menu(window, defender);
        }
        sfRenderWindow_display(window);
    }
}

void display_window()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
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
    defender.scene = INTRO;
    char *name = "Mydefender Project";
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    boucle(window, &defender);
}
