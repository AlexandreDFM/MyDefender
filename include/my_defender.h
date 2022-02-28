/*
** EPITECH PROJECT, 2021
** giantman.h
** File description:
** Header of Giantman
*/

#include "my.h"
#include "printf.h"
#include "colors.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>

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

enum type_monkey_t {
    DARTMONKEY,
    GLUEGUNNER,
    NINJA,
    SPIKEFACTORY,
    SUPERMONKEY,
    ICEMONKEY,
    BOMBSHOOTER,
};

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}go_t;

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

typedef struct monkey {
    int type;
    int damage;
    int lvl1;
    int lvl2;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect hitbox;
    sfVector2f resize;
    struct monkey *prev;
    struct monkey *next;
}monkey_t;

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

char *my_strdup(char *src);
int my_atoi(char const *str);
char *my_strcpy(char *dest, char const *src);
char **my_strtwa(char const *str, char *limit);
void *my_memset(void *dest, int value, int length);
void load_window();
defender_t init(void);
game_t init_textures(void);
char **init_waves(void);
void fill_waves(game_t *game);
void red_bloons(bloons_t *obj);
void blue_bloons(bloons_t *obj);
void green_bloons(bloons_t *obj);
void yellow_bloons(bloons_t *obj);
void fill_bloons(game_t *game);
bloons_t *load_bloons(game_t *game);
char *get_lines(char const *filepath);
void game(sfRenderWindow *win, game_t *game_s);
void menu(sfRenderWindow *window, defender_t *defender);
void check_pos(game_t *game, sfRenderWindow *window);
void intro(sfRenderWindow *window, defender_t *defender);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void display_cursor(sfRenderWindow *window, cursor_t cursor);
void display_go(sfRenderWindow *w, go_t go);
bouton_t create_bouton(char *tpath, sfVector2f pos, sfIntRect rect);
cursor_t create_cursor(char *tpath, sfVector2f pos, sfIntRect rect);
go_t create_go(char *tpath, sfVector2f pos, sfIntRect hitbox, sfVector2f size);
