/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** ex00
*/

#ifndef EX00_H_
#define EX00_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;


cthulhu_t *new_cthulhu();
koala_t *new_koala(char *, char);
void print_power(cthulhu_t *);
void attack(cthulhu_t *);
void sleeping(cthulhu_t *);
static void koala_initializer(koala_t *, char *, char );
static void cthulhu_initializer(cthulhu_t *);
void eat(koala_t *);

#endif /* !EX00_H_ */
