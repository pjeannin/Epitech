/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parser.h
*/
#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct bytebuf_s {
    uint8_t *buffer;
    uint32_t offset;
} bytebuf_t;

// initializer.c
int bytebuf_from_file(bytebuf_t *bytebuf, const char *path);
void bytebuf_free(bytebuf_t *bytebuf);
uint8_t bytebuf_flag(uint64_t flags, uint8_t pos);

// uint.c
uint8_t bytebuf_read_u8(bytebuf_t *bytebuf);
uint16_t bytebuf_read_u16(bytebuf_t *bytebuf);
uint32_t bytebuf_read_u32(bytebuf_t *bytebuf);
uint64_t bytebuf_read_u64(bytebuf_t *bytebuf);

// specials.c
char *bytebuf_read_string(bytebuf_t *bytebuf);