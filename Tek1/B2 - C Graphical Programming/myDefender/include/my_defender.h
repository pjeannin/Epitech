/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_defender
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include "lib.h"
#include "ennemy.h"
#include "button.h"
#include "text.h"
#include "vector.h"
#include "window.h"
#include "player.h"
#include "image.h"

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

typedef struct defender_s {
    ennemy_list_t *ennemy_list;
    defense_list_t *defense_list;
    projetcil_list_t *projectil_list;
    int level;
    castle_t *castle;
    button_list_t *button_list;
    sprite_list_t *map1;
    sprite_list_t *map2;
    sprite_list_t *map3;
    char **map1_construction;
    char **map2_construction;
    char **map3_construction;
    sfRenderWindow *window;
    int current_scene;
    sprite_list_t *current_map;
    char **current_mapconstruction;
    int score;
    int high_score;
    int money;
} defender_t;


/*** Initialization ***/

defender_t *init_defender(void);
ennemy_list_t *init_ennemy_list(int level, defender_t *defender);
castle_t *init_castle(int level);
defense_list_t *init_defense_list(void);
projetcil_list_t *init_projectil_list(void);
button_list_t *init_button_list(void);
button_sprite_t *init_sprite_button(sfVector2f position, sfVector2f size, char *filepath);
defense_list_t *create_empty_defense_list(void);
ennemy_list_t *create_empty_ennemy_list(void);
projetcil_list_t *create_empty_projectil_list(void);


/*** scene ***/

void scene_manager(defender_t *defender);
void intro_scene(defender_t *defender);
void main_menu_scene(defender_t *defender);
void event_intro_scene(defender_t *defender);
void event_main_menu_scene(defender_t *defender);
void draw_main_menu_button(defender_t *defender);
void rules_scene(defender_t *defender);
void game_scene(defender_t *defender);
void level_scene(defender_t *defender);
void display_level_button(defender_t *defender);
void event_level_scene(defender_t *defender);
int game_scene_event(defender_t *defender);
void dipslay_game_button(defender_t *defender);
void score_scene(defender_t *defender);
void display_score_button(defender_t *defender);
void event_score_scene(defender_t *defender);
void display_score(defender_t *defender);
void pause_scene(defender_t *defender);
void event_pause_scene(defender_t *defender);
void display_pause_scene_button(defender_t *defender);


/*** ennemy ***/

sfVector2f find_initial_ennemy_pos(defender_t *defender, int y_pos);
ennemy_t *create_ennemy(int hp, int ground, defender_t *defender, int y_pos);
sfVector2f move_ennemy(defender_t *defender, ennemy_t *ennemy);
void display_ennemy(defender_t *defender);
void ennemy_attack(defender_t *defender);
int add_ennemy(defender_t *defender);
int find_y(defender_t *defender, ennemy_t *ennemy, sfVector2f ennemy_postition);
int find_x(defender_t *defender, ennemy_t *ennemy, sfVector2f ennemy_postition);
void move_all_ennemy(defender_t *defender);
void delete_ennemy(defender_t *defender);


/*** player ***/

defense_t *create_defense(int type, int x, int y);
void display_defense(defender_t *defender);
int defense_attack(defender_t *defender);
void display_castle(defender_t *defender);
void add_defense_animation(sfEvent event, int new_defense,
defender_t *defender);
int add_defense(int new_defense, defender_t *defender, sfVector2f clic_pos);
void display_player_money(defender_t *defender);


/*** projectil ***/

void display_projectil(defender_t *defender);
projectil_t *add_projectil(ennemy_t *ennemy_id, defense_t *defense_id);
void move_projectil(defender_t *defender);

/*** free ***/

void free_defender(defender_t *defender);
void free_map(sprite_list_t *list);
void free_projectil_list(projetcil_list_t *list);
void free_castle(castle_t *castle);
void free_defense(defense_t *defense);
void free_ennemy(ennemy_t *ennemy);
void free_defense_list(defense_list_t *list);
void free_ennemy_list(ennemy_list_t *list);
void free_button_list(button_list_t *list);
void free_construction_map(char **map);


sprite_list_t *load_map(char *filepath, char ***construction_tab);
void draw_exit_button(defender_t *defender, sfRenderWindow *window);
void display_map(sprite_list_t *map, sfRenderWindow *window);
char *char_from_int(int nbr);
void str_rev(char *str);

#endif /* !MY_DEFENDER_H_ */
