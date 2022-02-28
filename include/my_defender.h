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

enum c_bloons_t {
    RED,
    BLUE,
    GREEN,
    YELLOW,
    RAINBOW,
    MOAB,
};

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}go_t;

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
    int clicked;
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
    int health;
    int damage;
    sfVector2f dir;
    sfVector2f pos;
    sfSprite *sprite;
    struct bloons *prev;
    struct bloons *next;
}bloons_t;

typedef struct game {
    bloons_t *head;
    bloons_t *bloon;
    char **waves;
    char *b_colors;
    int wave_nb;
    int wave_ind;
    sfTexture **t_array;
    sfSprite *hud;
    sfSprite *map;
    sfImage *map_c;
    const sfUint8 *pixels;
    sfVector3f *colors;
    sfVector2f *dirs;
    sfFloatRect frame;
}game_t;

typedef struct defender {
    enum scene_t scene;
    int valid[4];
    go_t intro;
    go_t title;
    go_t menu;
    cursor_t cursor;
    bouton_t bouton[4];
    sfEvent event;
    sfClock *clockintro;
}defender_t;

void load_window();
defender_t init(void);
char **init_waves(void);
char *my_strdup(char *src);
game_t init_textures(void);
int my_atoi(char const *str);
void fill_waves(game_t *game);
void fill_bloons(game_t *game);
void red_bloons(bloons_t *obj);
void delete_bloon(game_t *game);
void blue_bloons(bloons_t *obj);
void green_bloons(bloons_t *obj);
void yellow_bloons(bloons_t *obj);
bloons_t *load_bloons(game_t *game);
char *get_lines(char const *filepath);
void display_go(sfRenderWindow *w, go_t go);
char *my_strcpy(char *dest, char const *src);
char **my_strtwa(char const *str, char *limit);
void game(sfRenderWindow *win, game_t *game_s);
void *my_memset(void *dest, int value, int length);
void check_pos(game_t *game, sfRenderWindow *window);
void display_menu(sfRenderWindow *window, menu_t menu);
void menu(sfRenderWindow *window, defender_t *defender);
void intro(sfRenderWindow *window, defender_t *defender);
void display_intro(sfRenderWindow *window, intro_t intro);
void display_title(sfRenderWindow *window, title_t title);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void display_cursor(sfRenderWindow *window, cursor_t cursor);
menu_t create_menu(char *tpath, sfVector2f pos, sfIntRect rect);
intro_t create_intro(char *tpath, sfVector2f pos, sfIntRect rect);
title_t create_title(char *tpath, sfVector2f pos, sfIntRect rect);
bouton_t create_bouton(char *tpath, sfVector2f pos, sfIntRect rect);
cursor_t create_cursor(char *tpath, sfVector2f pos, sfIntRect rect);
go_t create_go(char *tpath, sfVector2f pos, sfIntRect hitbox, sfVector2f size);
