/*
** EPITECH PROJECT, 2021
** giantman.h
** File description:
** Header of Giantman
*/

#include "my.h"
#include "printf.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

enum scene_t {
    INTRO,
    MENU,
    GAME,
    PAUSE,
    GAMEOVER,
    GAMEWIN,
    TRANSITION,
    TRANSITIONGO,
    TRANSITIONWIN,
    TRANSITIONMENU,
};

typedef struct intro {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}intro_t;

typedef struct title {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}title_t;

typedef struct menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}menu_t;

typedef struct bouton {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}bouton_t;

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}cursor_t;

typedef struct defender {
    enum scene_t scene;
    intro_t intro;
    cursor_t cursor;
    title_t title;
    menu_t menu;
    int valid[4];
    bouton_t bouton[4];
    sfEvent event;
    sfClock *clockintro;
}defender_t;

#ifndef DEFENDER
    #define DEFENDER

void display_window();
void display_intro(sfRenderWindow *window, intro_t intro);
void display_title(sfRenderWindow *window, title_t title);
void display_menu(sfRenderWindow *window, menu_t menu);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void display_cursor(sfRenderWindow *window, cursor_t cursor);
intro_t create_intro(char *tpath, sfVector2f pos, sfIntRect rect);
title_t create_title(char *tpath, sfVector2f pos, sfIntRect rect);
menu_t create_menu(char *tpath, sfVector2f pos, sfIntRect rect);
bouton_t create_bouton(char *tpath, sfVector2f pos, sfIntRect rect);
cursor_t create_cursor(char *tpath, sfVector2f pos, sfIntRect rect);

void menu(sfRenderWindow *window, defender_t *defender);


#endif
