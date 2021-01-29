/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** add_projectil
*/

#include "my_defender.h"

projectil_t *add_projectil(ennemy_t *ennemy_id, defense_t *defense_id)
{
    projectil_t *projectil = malloc(sizeof(projectil_t));

    if (projectil == NULL)
        return (NULL);
    projectil->defense_id = defense_id;
    projectil->ennemy_id = ennemy_id;
    projectil->display = 1;
    projectil->sprite = init_image("PNG/Retina/towerDefense_tile251.png",
    0, defense_id->pos.x, defense_id->pos.y);
    return (projectil);
}