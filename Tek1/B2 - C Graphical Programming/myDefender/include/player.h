/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** player
*/

#include "SFML/Graphics.h"
#include "image.h"

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct castle_s {
    picture_t *display_sprite;
    sfSprite *upper_sprite;
    sfSprite *middle_sprite;
    sfSprite *lower_sprite;
    int health;
    int init_health;
    picture_t *full_life;
    picture_t *third_life;
    picture_t *mid_life;
    picture_t *low_life;
    picture_t *no_life;
    sfVector2f pos;
} castle_t;

typedef struct defense_s {
    picture_t *sprite;
    sfVector2f pos;
    int type;
    int ground_attack;
    int sky_attack;
    int health;
    int stroke;
    int shoot;
} defense_t;

typedef struct defense_list_s {
    struct defense_list_s *prev;
    struct defense_list_s *next;
    defense_t *defnse;
} defense_list_t;

typedef struct projectil_s {
    picture_t *sprite;
    int display;
    struct ennemy_s *ennemy_id;
    struct defense_s *defense_id;
} projectil_t;

typedef struct projetcil_list_s {
    struct projectil_s *projectil;
    struct projetcil_list_s *next;
    struct projetcil_list_s *prev;
} projetcil_list_t;

#endif /* !PLAYER_H_ */
