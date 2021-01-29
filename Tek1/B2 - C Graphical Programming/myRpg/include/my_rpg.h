/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "maps.h"
#include "define.h"
#include "my.h"
#include "menu.h"
#include "game.h"
#include "bytebuf.h"
#include "character.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "maps.h"
#include "define.h"
#include "my.h"
#include "menu.h"
#include "bytebuf.h"
#include "free.h"
#include "particules.h"

#ifndef MY_RPG_H_
#define MY_RPG_H_

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920

typedef struct stats_s {
    int life;
    int damage;
    int xp;
    int level;
} stats_t;

typedef struct guardian_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    int isalave;
    int move_side;
    int speed;
    int damage;
    int has_shoot;
    int life;
} guardian_t;

typedef struct quete_s {
    int done;
    sfSprite *sprite;
} quete_t;

typedef struct object_list_s {
    sfSprite *sprite;
    sfVector2f pos;
    int istake;
    int isused;
} object_list_t;

typedef struct map_s {
    sfSprite *map;
    int anim;
} map_t;

typedef struct game_s {
    map_t *map;
    object_list_t object_list[4];
    guardian_t guardian[4];
    guardian_t boss;
    quete_t quete[3];
    stats_t player_stats;
    int cur_quete;
    int need_to_display_quete;
    sfUint8 frame_buffer[WINDOW_HEIGHT * WINDOW_WIDTH * 4];
    sfSprite *win_menu;
} game_t;

int rpg(game_t *game_struct);
int play(window_t *win, charact_t *charact, game_t *game_struct);
int init_window(window_t *win);
void init_map(game_t *game_struct);
void play_clock(window_t *win, charact_t *charact, game_t *game_struct);
void play_game(window_t *win, charact_t *charact, game_t *game_struct);
void draw_map(game_t *game_struct, window_t *win);
int window_event(window_t *win, charact_t *charact, game_t *game_struct);
int check_key_caract(window_t *win, charact_t *charact, game_t *game_struct);
void add_object(game_t *game_struct, char *filepath, sfVector2f pos);
void move_map(game_t *game_struct);
void draw_objects(game_t *game_struct, window_t *win, charact_t *charact);
void init_object_list(game_t *game_struct);
void check_key_take_object(window_t *win, charact_t *charact, game_t *game_struct);
void ask_quete(game_t *game_struct);
void init_quete(game_t *game_struct);
void display_quete(game_t *game_struct, window_t *win);
sfText *set_text(char *str, int size, int x, int y);
void updtade_quete(game_t *game_struct);
void init_guardian(game_t *game_struct);
void set_guardian_pos(game_t *game_struct, int guardian, sfVector2f pos);
void draw_guardian(game_t *game_struct, window_t *win);
void move_guardian(game_t *game_struct);
void init_stats(game_t *game_struct);
void guardian_damage(game_t *game_struct, charact_t *charact);
void player_damage(game_t *game_struct, charact_t *charact, window_t *win);
void update_guardian_life(game_t *game_struct);
void update_particules(game_t *game_struct);
void create_partiules(game_t *game_struct, int x, int y);
void draw_particules(game_t *game_struct, window_t *win);
void init_frame_buffer(game_t *game_struct);
int init_inventory(game_t *game_struct);
void init_menu(game_t *game_struct);
void set_string(game_t *game_struct);
void init_boss(game_t *game_struct);
void boss_damage(game_t *game_struct, charact_t *charact);
void give_life_back(game_t *game_struct, window_t *win);
void death_boss(game_t *game_struct);
void update_level(game_t *game_struct);
int init_rpg(charact_t *charact, window_t *win, game_t *game_struct);
void create_rain(game_t *game_struct);
void init_die(void);
void init_heart(void);
void init_end(game_t *game_struct);
void end_event(window_t *win, game_t *game_struct);
void end_menu(game_t *game_struct, window_t *win);
int init_music(window_t *win);
void init_end(game_t *game_struct);
int base_pos_echap(void);
int press_echap(window_t *win);
void check_button(window_t *win);
void anime_echap(window_t *win);
void check_button_end(window_t *win);

#endif