/*
** EPITECH PROJECT, 2021
** giantman.h
** File description:
** Header of Giantman
*/

#include "my.h"
#include "printf.h"
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <math.h>
#include "colors.h"
#define PI 3.141592654

#pragma once

enum boolean_t {
    FALSE = 0,
    TRUE = 1,
};

enum scene_t {
    INTRO,
    MENU,
    SETTINGS,
    HOW_TO_PLAY,
    GAME,
    PAUSE,
    GAMEOVER,
    GAMEWIN,
    TRANSITION,
    TRANSITIONGO,
    TRANSITIONWIN,
    TRANSITIONMENU,
};

enum c_monkey_t {
    MONKEY_SELECT = -1,
    NO_MONKEY = 0,
    DART_MONKEY = 1,
    TACK_SHOOTER = 2,
    NINJA_MONKEY = 5,
    BOMB_SHOOTER = 6,
    ICE_MONKEY = 7,
    GLUE_GUNNER = 8,
    SUPER_MONKEY = 11,
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

typedef struct r_hitbox {
    sfRectangleShape *shape;
    sfColor color;
    sfVector2f pos;
    sfIntRect rect;
}r_hb_t;

typedef struct c_hitbox {
    sfCircleShape *shape;
    sfColor color;
    sfVector2f pos;
    float radius;
}c_hb_t;

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

typedef struct bloons {
    int type;
    float speed;
    int health;
    int damage;
    sfVector2f dir;
    sfVector2f pos;
    sfSprite *sprite;
    struct bloons *prev;
    struct bloons *next;
}bloons_t;

typedef struct special_tower_1
{
    int damage;
    int nb_mun;
}s_t_1_t;

typedef struct special_tower_2
{
    int damage;
}s_t_2_t;

typedef struct monkey {
    enum c_monkey_t type;
    enum boolean_t clicked;
    int radius;
    int damage;
    int lvl1;
    int lvl2;
    int attackspeed;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect hitbox;
    sfVector2f resize;
    sfClock *clockattack;
    c_hb_t range;
    go_t avatar;
    go_t upgrade1;
    go_t upgrade2;
    bloons_t *blooncibled;
    sfText *sell;
    r_hb_t hitbox_sell;
    sfText *priority;
    struct monkey *prev;
    struct monkey *next;
}monkey_t;

typedef struct cursor {
    enum c_monkey_t t_to;
    monkey_t monkey;
    c_hb_t monkey_c;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f resize;
}cursor_t;

typedef struct game {
    bloons_t *head;
    bloons_t *bloon;
    monkey_t *monkey_head;
    monkey_t *monkey;
    char **tower_stats;
    char **waves;
    char *b_colors;
    int wave_nb;
    int wave_ind;
    int money;
    int health;
    int ff;
    sfTexture **t_array;
    sfSprite *hud;
    sfSprite *map;
    sfSprite *up_gui;
    bouton_t p_but[2];
    sfImage *map_c;
    sfFont *font;
    sfText *sc;
    sfText *wav;
    sfText *h;
    const sfUint8 *pixels;
    sfVector3f *colors;
    sfVector2f *dirs;
    sfFloatRect frame;
    sfTexture *t_monkey;
    sfFloatRect **tower_box;
    r_hb_t tower_hitbox[14];
    sfIntRect *r_to;
    sfClock *c;
}game_t;

typedef struct pause_t {
    sfColor color;
    sfRectangleShape *fade;
    bouton_t pause_b[8];
}pause_t;

typedef struct defender {
    enum scene_t scene;
    int playing;
    int state;
    int aplay;
    int valid[4];
    go_t intro;
    go_t title;
    go_t menu;
    cursor_t cursor;
    bouton_t bouton[4];
    pause_t p_menu;
    sfEvent event;
    sfSoundBuffer *slashbuffer;
    sfSoundBuffer *popbuffer[4];
    sfSoundBuffer *towertkbuffer;
    sfSoundBuffer *towerplbuffer;
    sfSoundBuffer *towerdlbuffer;
    sfSound *slash;
    sfSound *pop[4];
    sfSound *towertk;
    sfSound *towerpl;
    sfSound *towerdl;
    sfMusic *menu_music;
    sfMusic *game_music;
    sfFont *font;
    sfText *help_txt;
    sfClock *clockintro;
}defender_t;

char *get_lines(char const *filepath);
void my_free_array(char **array);
void load_window();
defender_t init(void);
char *my_itoa(int num);
char **init_waves(void);
char *my_strdup(char *src);
game_t init_textures(void);
int my_atoi(char const *str);
void fill_hudtowers(game_t *g);
void fill_waves(game_t *game);
void fill_bloons(game_t *game);
void fill_tower_box(game_t *game);
void fill_debug_t_box(game_t *game);
void check_thud_hb(sfRenderWindow *w, game_t *g, defender_t *d);
void tower_node(sfRenderWindow *w, game_t *game, defender_t *defender);
void display_tower_hitbox(sfRenderWindow *w, game_t *game, defender_t *defender);
c_hb_t c_monkey_c(sfVector2f pos, float radius, sfVector2f size, sfColor color);
monkey_t *first_monkey(game_t *game, defender_t *defender, sfVector2f pos);
void add_monkey(game_t *game, defender_t *defender, sfVector2f pos);
void display_monkey_hb(sfRenderWindow *w, c_hb_t hb_monkey);
int check_t_pl(game_t *game, defender_t *defender);
void draw_score(game_t *game, sfRenderWindow *win);
void fill_r_to(game_t *game);
int tower(int mode);
void load_window();
defender_t init(void);
char **init_waves(void);
game_t init_textures(void);
char *my_strdup(char *src);
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
void *my_memset(void *dest, int value, int length);
void check_pos(game_t *game, sfRenderWindow *window);
void game(sfRenderWindow *win, game_t *game_s);
void display_menu(sfRenderWindow *window, menu_t menu);
void menu(sfRenderWindow *window, defender_t *defender);
void intro(sfRenderWindow *window, defender_t *defender);
void display_intro(sfRenderWindow *window, intro_t intro);
void display_title(sfRenderWindow *window, title_t title);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void display_cursor(sfRenderWindow *window, game_t *game, defender_t *defender, cursor_t cursor);
void display_monkey(sfRenderWindow *w, monkey_t monkey);
menu_t create_menu(char *tpath, sfVector2f pos, sfIntRect rect);
intro_t create_intro(char *tpath, sfVector2f pos, sfIntRect rect);
title_t create_title(char *tpath, sfVector2f pos, sfIntRect rect);
bouton_t create_bouton(char *tpath, sfVector2f pos, sfIntRect rect);
cursor_t create_cursor(char *tpath, sfVector2f pos, sfIntRect rect);
monkey_t c_monkey(sfVector2f pos, sfIntRect hitbox, sfVector2f size, int type);
void ig_but(game_t *game, defender_t *defender, sfRenderWindow *win);
void game(sfRenderWindow *win, game_t *game_s, defender_t *defender);
void pause_f(sfRenderWindow *window, defender_t *defender, game_t *game);
go_t create_go(char *tpath, sfVector2f pos, sfIntRect hitbox, sfVector2f size);
