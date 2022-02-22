/*
** EPITECH PROJECT, 2021
** giantman.h
** File description:
** Header of Giantman
*/

#include "my.h"
#include "printf.h"
#include <SFML/Graphics.h>
#include<fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <math.h>
#include "colors.h"

#pragma once

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

typedef struct bloons
{
    int type;
    int speed;
    int t_type;
    int health;
    int damage;
    sfVector2f dir;
    sfVector2f pos;
    sfSprite *sprite;
    struct bloons *next;
}bloons_t;

typedef struct game {
    bloons_t bloon;
    sfTexture **t_array;
    sfSprite *hud;
    sfSprite *map;
    sfImage *map_c;
    sfUint8 *pixels;
}game_t;

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

void load_window();
int my_atoi(char const *str);
bloons_t load_bloons(game_t *game);
char *get_lines(char const *filepath);
char **my_str_to_word_array(char *str);
void game(sfRenderWindow *win, game_t *game_s);
void display_menu(sfRenderWindow *window, menu_t menu);
void menu(sfRenderWindow *window, defender_t *defender);
void display_intro(sfRenderWindow *window, intro_t intro);
void display_title(sfRenderWindow *window, title_t title);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void display_cursor(sfRenderWindow *window, cursor_t cursor);
menu_t create_menu(char *tpath, sfVector2f pos, sfIntRect rect);
intro_t create_intro(char *tpath, sfVector2f pos, sfIntRect rect);
title_t create_title(char *tpath, sfVector2f pos, sfIntRect rect);
bouton_t create_bouton(char *tpath, sfVector2f pos, sfIntRect rect);
cursor_t create_cursor(char *tpath, sfVector2f pos, sfIntRect rect);
game_t *check_pos(game_t *game, sfRenderWindow *window);
