/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>
#include <SFML/Audio.h>

#ifndef MENU_H_
#define MENU_H_

typedef struct parallax_s
{
    sfSprite *S_parallax;
    sfTexture *T_parallax;
    sfVector2f par_pos;

} parallax_t;

parallax_t *tabpar;

typedef struct menugame_s
{
    sfSprite *S_menugame;
    sfTexture *T_menugame;
    sfVector2f menugame_pos;

} menugame_t;

menugame_t *tabgame;

typedef struct inventory_s
{
    sfSprite *S_invent;
    sfTexture *T_invent;
    sfVector2f invent_pos;
    sfText *text;
    sfFont *font;
    sfVector2f text_pos;

} inventory_t;

inventory_t *tabinvent;

typedef struct button_s
{
    sfSprite *S_button;
    sfTexture *T_button;
    sfVector2f but_pos;
    sfVector2f but_scale;

} button_t;

button_t *but;

typedef struct window_s
{
    float seconds;
    int choice;
    int screen;
    int echap_switch;
    int choice_echap;
    int dis_invent;
    int h_play;
    int die;
    sfRenderWindow *window;
    sfEvent event;
    sfTime time;
    sfClock *clock;
    sfVector2i vec;
    sfMusic *music;
} window_t;

int menu(window_t *win);
int init_parallax(void);
int init_texture_par(void);
void draw_menu(window_t *win);
int destroy_menu(void);
int init_button(void);
int parallax(void);
int check_key_echap(window_t *win);
int draw_echap(window_t *win);
int init_echap(void);
int draw_inventory(window_t *win);
int check_key_inventory(window_t *win);

#endif