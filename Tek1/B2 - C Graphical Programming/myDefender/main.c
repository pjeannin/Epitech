/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main
*/

#include "my_defender.h"


int main(void)
{
    defender_t *defender = init_defender();
    sfEvent event;

    if (!defender)
        return (84);
    scene_manager(defender);
    free_defender(defender);
    return (0);
}