/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** ex00
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;

    printf("----\nBuilding %s\n", this->m_name);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    this->m_parent = *new_cthulhu();
    this->m_parent.m_name = strdup(_name);
    this->m_is_a_legend = _is_A_Legend;
    if (_is_A_Legend == 0)
        this->m_parent.m_power = 0;

    printf("Building %s\n", this->m_parent.m_name);
}

cthulhu_t *new_cthulhu(void)
{
    cthulhu_t *this = malloc(sizeof(cthulhu_t));

    cthulhu_initializer(this);

    return (this);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *this = malloc(sizeof(koala_t));

    koala_initializer(this, name, is_a_legend);

    return (this);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power < 42) {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
        return;
    }
    this->m_power -= 42;
    printf("%s attacks and destroys the city\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}