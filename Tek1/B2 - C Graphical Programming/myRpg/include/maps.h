/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** maps.h
*/
#pragma once

#include <stdint.h>
#include "bytebuf.h"

typedef struct damage_s {
    uint16_t speed;
    uint16_t amout;
} damage_t;

typedef struct case_s {
    uint8_t solid;
    damage_t damage;
    uint16_t event;
    uint8_t texture0;
    uint8_t texture2;
} case_t;

// typedef struct map_s {
//     int id;
//     char *name;
//     uint8_t height;
//     uint8_t width;
//     uint8_t background;
//     case_t **cases;
// } map_t;

// map_t *read_map(bytebuf_t *bytebuf)