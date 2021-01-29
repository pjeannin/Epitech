/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

int set_position_text(void)
{
    tabinvent[1].text_pos.x = 535;
    tabinvent[1].text_pos.y = 300;
    tabinvent[2].text_pos.x = 535;
    tabinvent[2].text_pos.y = 385;
    tabinvent[3].text_pos.x = 535;
    tabinvent[3].text_pos.y = 475;
    tabinvent[4].text_pos.x = 285;
    tabinvent[4].text_pos.y = 445;
    tabinvent[5].text_pos.x = 285;
    tabinvent[5].text_pos.y = 502;
    tabinvent[6].text_pos.x = 1700;
    tabinvent[6].text_pos.y = 30;
    return (0);
}

void set_string(game_t *game_struct)
{
    int potion = 0;

    for (int i = 1; i < 4; ++i)
        if (game_struct->object_list[i].istake == 1 &&
        game_struct->object_list[i].isused == 0)
            ++potion;
    sfText_setString(tabinvent[1].text,
    char_from_int(game_struct->player_stats.life));
    sfText_setString(tabinvent[2].text,
    char_from_int(game_struct->player_stats.damage
    * game_struct->player_stats.level));
    sfText_setString(tabinvent[3].text,
    char_from_int(game_struct->player_stats.level));
    sfText_setString(tabinvent[4].text,
    char_from_int(game_struct->object_list[0].istake));
    sfText_setString(tabinvent[5].text,
    char_from_int(potion));
    sfText_setString(tabinvent[6].text,
    char_from_int(game_struct->player_stats.life));
}

int init_stat(game_t *game_struct)
{
    set_position_text();
    for (int i = 1; i < 7; i++) {
        tabinvent[i].text = sfText_create();
        tabinvent[i].font = sfFont_createFromFile("./ressources/ttf/text.ttf");
        sfText_setFont(tabinvent[i].text, tabinvent[i].font);
        sfText_setCharacterSize(tabinvent[i].text, 50);
        sfText_setPosition(tabinvent[i].text, tabinvent[i].text_pos);
    }
    sfText_setCharacterSize(tabinvent[4].text, 40);
    sfText_setCharacterSize(tabinvent[5].text, 40);
    set_string(game_struct);
    return (0);
}

int init_inventory(game_t *game_struct)
{
    tabinvent = malloc(sizeof(inventory_t) * 9);

    tabinvent[0].S_invent = sfSprite_create();
    tabinvent[0].T_invent =
    sfTexture_createFromFile("./ressources/inventaire/inventaire.png", NULL);
    sfSprite_setTexture(tabinvent[0].S_invent, tabinvent[0].T_invent, sfTrue);
    tabinvent[0].invent_pos.x = 200;
    tabinvent[0].invent_pos.y = 200;
    sfSprite_setPosition(tabinvent[0].S_invent, tabinvent[0].invent_pos);
    init_stat(game_struct);
    init_die();
    init_heart();
    return (0);
}

int draw_inventory(window_t *win)
{
    if (win->dis_invent == 1) {
        sfRenderWindow_drawSprite(win->window, tabinvent[0].S_invent, NULL);
        for (int i = 1; i < 6; i++)
            sfRenderWindow_drawText(win->window, tabinvent[i].text, NULL);
    }
    if (win->die == 1)
        sfRenderWindow_drawSprite(win->window, tabinvent[7].S_invent, NULL);
    sfRenderWindow_drawSprite(win->window, tabinvent[8].S_invent, NULL);
    sfRenderWindow_drawText(win->window, tabinvent[6].text, NULL);
    return (0);
}