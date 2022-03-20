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
    MAP_SELECT,
    GAME1,
    GAME2,
    GAME3,
    PAUSE,
    GAMEOVER,
    GAMEWIN,
    TRANSITION,
    TRANSITIONGO,
    TRANSITIONWIN,
    TRANSITIONMENU,
};

enum difficulty_t {
    EASY = 30,
    MEDIUM = 40,
    HARD = 50,
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
    sfClock *clock;
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
    int price1;
    int price2;
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
    r_hb_t hitbox_up1;
    r_hb_t hitbox_up2;
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
    int cleared;
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
    int wavenb;
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
    r_hb_t gameoverscreen;
    sfText *gamestate;
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
    enum difficulty_t difficulty;
    int playing;
    int state;
    int aplay;
    int valid[6];
    int fps;
    int settings_click;
    int map_select;
    int volume_buf;
    int v_buf_save;
    int volume_buf2;
    int v_buf2_save;
    int v_music;
    int v_save;
    go_t intro;
    go_t title;
    go_t menu;
    go_t settings;
    go_t settings_b;
    go_t settings_c;
    go_t settings_l;
    go_t htp_leave;
    go_t map_select_b;
    go_t map_select_m[4];
    go_t map_select_bl;
    go_t map_select_br;
    go_t map_select_d;
    go_t map_select_l;
    bouton_t map_select_go;
    r_hb_t settings_bar;
    r_hb_t htpback;
    cursor_t cursor;
    bouton_t bouton[6];
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
    sfMusic *m_music;
    sfMusic *g_music;
    sfFont *font;
    sfText *help_txt;
    sfClock *clockintro;
}defender_t;

void load_window();
defender_t init_map_select2(defender_t d);
defender_t init_menu_boutons(defender_t defender);
defender_t init_map_select1(defender_t d);
defender_t init_htp(defender_t d);
defender_t init_settings(defender_t d);
defender_t condition_init(defender_t d, int i, int *indx, int indy);
defender_t init_music1(defender_t d);
defender_t init_music2(defender_t d);
defender_t init_music3(defender_t d);
int tower(int mode);
defender_t init(void);
defender_t init(void);
char *my_itoa(int num);
char **init_waves(void);
char *my_strdup(char *src);
int my_atoi(char const *str);
void fill_waves(game_t *game);
void fill_hudtowers(game_t *g);
void fill_bloons(game_t *game);
void delete_tower(game_t *game);
void my_free_array(char **array);
void fill_tower_box(game_t *game);
void uninit_textures(defender_t *defender, game_t *game);
void fill_debug_t_box(game_t *game);
char *get_lines(char const *filepath);
void select_map(sfRenderWindow *w, defender_t *defender, game_t *game);
void tower_attack(game_t *game, defender_t *defender);
void check_thud_hb(sfRenderWindow *w, game_t *g, defender_t *d);
void tower_node(sfRenderWindow *w, game_t *game, defender_t *defender);
void game_win(sfRenderWindow *w, defender_t *defender, game_t *game);
void monkey_management(sfRenderWindow *w, game_t *game, defender_t *d);
void d_tower_hitbox(sfRenderWindow *w, game_t *game, defender_t *defender);
void init_special(defender_t *defender, game_t *g);
r_hb_t c_r_hitbox(sfVector2f pos, sfIntRect rect, sfVector2f size, sfColor c);
c_hb_t c_c_hitbox(sfVector2f pos, float radius, sfVector2f size, sfColor c);
monkey_t *first_monkey(game_t *game, defender_t *defender, sfVector2f pos);
void add_monkey(game_t *game, defender_t *defender, sfVector2f pos);
void display_circle_hb(sfRenderWindow *w, c_hb_t hb_monkey);
void is_bouton(sfRenderWindow *window, defender_t *defender);
int check_t_pl(game_t *game, defender_t *defender);
sfText *create_text(sfFont *font, sfVector2f pos, char *txt, int size);
void skill_tree_display(sfRenderWindow *w, game_t *game);
void skill_tree(game_t *game, defender_t *defender);
void how_to_play(sfRenderWindow *win, defender_t *defender);
void all_uninit(defender_t *defender, game_t *game);
void settings(sfRenderWindow *win, defender_t *defender);
void bloon_management(sfRenderWindow *win, game_t *game_s,
defender_t *defender);
char *my_strcat_alloc(char *dest, char const *src);
void draw_score(sfRenderWindow *win, game_t *game, defender_t *defender);
void fill_r_to(game_t *game);
char **init_waves(void);
void init_textures(defender_t *defender, game_t *game);
char *my_strdup(char *src);
int my_atoi(char const *str);
void fill_waves(game_t *game);
void fill_bloons(game_t *game);
void red_bloons(bloons_t *obj);
void delete_bloon(game_t *game);
void blue_bloons(bloons_t *obj);
void green_bloons(bloons_t *obj);
void yellow_bloons(bloons_t *obj);
bloons_t *load_bloons(defender_t *defender, game_t *game);
char *get_lines(char const *filepath);
void display_go(sfRenderWindow *w, go_t go);
char *my_strcpy(char *dest, char const *src);
char **my_strtwa(char const *str, char *limit);
void *my_memset(void *dest, int value, int length);
void check_pos(game_t *game, sfRenderWindow *window);
void display_menu(sfRenderWindow *window, menu_t menu);
void game_over(sfRenderWindow *w, defender_t *defender, game_t *game);
void display_rect_hb(sfRenderWindow *w, r_hb_t hb);
void menu(sfRenderWindow *window, defender_t *defender, game_t *game);
void intro(sfRenderWindow *window, defender_t *defender);
void display_title(sfRenderWindow *window, title_t title);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void d_cursor(sfRenderWindow *w, game_t *g, defender_t *d, cursor_t cursor);
void display_monkey(sfRenderWindow *w, monkey_t monkey);
menu_t create_menu(char *tpath, sfVector2f pos, sfIntRect rect);
title_t create_title(char *tpath, sfVector2f pos, sfIntRect rect);
bouton_t create_bouton(char *tpath, sfVector2f pos, sfIntRect rect);
cursor_t create_cursor(char *tpath, sfVector2f pos, sfIntRect rect);
monkey_t c_monkey(sfVector2f pos, sfIntRect hitbox, sfVector2f size, int type);
void ig_but(game_t *game, defender_t *defender, sfRenderWindow *win);
void game(sfRenderWindow *win, game_t *game_s, defender_t *defender);
void pause_f(sfRenderWindow *window, defender_t *defender, game_t *game);
go_t create_go(char *tpath, sfVector2f pos, sfIntRect hitbox, sfVector2f size);
void change_bouton_go(sfRenderWindow *window, defender_t *defender);
void change_bouton_leave_sm(sfRenderWindow *w, defender_t *d);
void change_bouton_lr(sfRenderWindow *win, defender_t *d);
void change_map(sfRenderWindow *win, defender_t *d);
void monkey_up_display(sfRenderWindow *w, game_t *game, defender_t *defender);
void monkey_upgrade(game_t *game, defender_t *defender, monkey_t *obj);
void check_tower_radius(game_t *g, defender_t *defender);
void click_fps(sfRenderWindow *win, defender_t *def);
void bar_volume(sfRenderWindow *win, defender_t *def);
void config_sound(sfRenderWindow *win, defender_t *defender, game_t *game, int i);
