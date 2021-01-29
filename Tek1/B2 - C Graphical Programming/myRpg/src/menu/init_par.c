/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

int base_pos_par(void)
{
    tabpar[1].par_pos.x = -1920;
    tabpar[3].par_pos.x = -1920;
    tabpar[5].par_pos.x = -1920;
    tabpar[7].par_pos.x = -1920;
    tabpar[9].par_pos.x = -1920;
    tabpar[11].par_pos.x = -1920;
    tabpar[13].par_pos.x = -1920;
    tabpar[15].par_pos.x = -1920;
    tabpar[0].par_pos.x = 0;
    tabpar[2].par_pos.x = 0;
    tabpar[4].par_pos.x = 0;
    tabpar[6].par_pos.x = 0;
    tabpar[8].par_pos.x = 0;
    tabpar[10].par_pos.x = 0;
    tabpar[12].par_pos.x = 0;
    tabpar[14].par_pos.x = 0;
    return (0);
}

int init_texture_par(void)
{
    tabpar[0].T_parallax =
    sfTexture_createFromFile("./ressources/menu/sky.png", NULL);
    tabpar[1].T_parallax =
    sfTexture_createFromFile("./ressources/menu/sky.png", NULL);
    tabpar[2].T_parallax =
    sfTexture_createFromFile("./ressources/menu/clouds_1.png", NULL);
    tabpar[3].T_parallax =
    sfTexture_createFromFile("./ressources/menu/clouds_1.png", NULL);
    tabpar[4].T_parallax =
    sfTexture_createFromFile("./ressources/menu/rocks.png", NULL);
    tabpar[5].T_parallax =
    sfTexture_createFromFile("./ressources/menu/rocks.png", NULL);
    tabpar[6].T_parallax =
    sfTexture_createFromFile("./ressources/menu/clouds_2.png", NULL);
    tabpar[7].T_parallax =
    sfTexture_createFromFile("./ressources/menu/clouds_2.png", NULL);
    return (0);
}

int init_texture_par_2(void)
{
    tabpar[8].T_parallax =
    sfTexture_createFromFile("./ressources/menu/ground_1.png", NULL);
    tabpar[9].T_parallax =
    sfTexture_createFromFile("./ressources/menu/ground_1.png", NULL);
    tabpar[10].T_parallax =
    sfTexture_createFromFile("./ressources/menu/ground_2.png", NULL);
    tabpar[11].T_parallax =
    sfTexture_createFromFile("./ressources/menu/ground_2.png", NULL);
    tabpar[12].T_parallax =
    sfTexture_createFromFile("./ressources/menu/ground_3.png", NULL);
    tabpar[13].T_parallax =
    sfTexture_createFromFile("./ressources/menu/ground_3.png", NULL);
    tabpar[14].T_parallax =
    sfTexture_createFromFile("./ressources/menu/plant.png", NULL);
    tabpar[15].T_parallax =
    sfTexture_createFromFile("./ressources/menu/plant.png", NULL);
    return (0);
}

int init_parallax(void)
{
    tabpar = malloc(sizeof(parallax_t) * 16);

    for (int i = 0; i < 16; i++)
        tabpar[i].S_parallax = sfSprite_create();
    init_texture_par();
    init_texture_par_2();
    for (int i = 0; i < 16; i++)
        sfSprite_setTexture(tabpar[i].S_parallax, tabpar[i].T_parallax, sfTrue);
    base_pos_par();
    for (int i = 0; i < 16; i++)
        sfSprite_setPosition(tabpar[i].S_parallax, tabpar[i].par_pos);
    return (0);
}