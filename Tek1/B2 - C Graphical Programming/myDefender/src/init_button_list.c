/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_button
*/

#include "my_defender.h"

void init_level_menu_button(button_list_t *button_list)
{
    button_list->level1_text = set_text("LEVEL 1", 80, 845, 390);
    button_list->level2_button = init_button(create_sfvector2f(700, 600)
    , create_sfvector2f(500, 80), sfRed);
    button_list->level2_text = set_text("LEVEL 2", 80, 845, 590);
    button_list->level3_button = init_button(create_sfvector2f(700, 800)
    , create_sfvector2f(500, 80), sfRed);
    button_list->level3_text = set_text("LEVEL 3", 80, 845, 790);
}

void init_gamebutton(button_list_t *button_list)
{
    button_list->defense1 = init_sprite_button(create_sfvector2f(1520, 100),
    create_sfvector2f (360, 360), "PNG/defense1_button.png");
    button_list->defense2 = init_sprite_button(create_sfvector2f(1520, 480),
    create_sfvector2f (360, 360), "PNG/defense2_button.png");
    button_list->pause = init_sprite_button(create_sfvector2f(20, 1000),
    create_sfvector2f(64, 64), "PNG/pause.png");
    button_list->menu_button = init_button(create_sfvector2f(90, 850),
    create_sfvector2f(255, 110), sfRed);
}

void init_pause_menu_button(button_list_t *button_list)
{
    button_list->menu_text = set_text("MENU", 100, 100, 845);
    button_list->play_again_button = init_button(create_sfvector2f(1330, 850),
    create_sfvector2f(500, 110), sfRed);
    button_list->play_again_text = set_text("PLAY AGAIN", 100, 1340, 845);
    button_list->resume_button = init_button(create_sfvector2f(700, 400)
    , create_sfvector2f(500, 80), sfBlue);
    button_list->resume_text = set_text("RESUME", 80, 820, 390);
    button_list->restart_button = init_button(create_sfvector2f(700, 600)
    , create_sfvector2f(500, 80), sfBlue);
    button_list->restart_text = set_text("RESTART", 80, 815, 590);
    button_list->main_menu_button = init_button(create_sfvector2f(700, 800)
    , create_sfvector2f(500, 80), sfBlue);
    button_list->main_menu_text = set_text("MAIN MENU", 80, 770, 790);
}

button_list_t *init_button_list(void)
{
    button_list_t *button_list = malloc(sizeof(button_list_t));

    if (button_list == NULL)
        return (NULL);
    button_list->exit_button = init_button(create_sfvector2f(1700, 15)
    , create_sfvector2f(200, 50), sfBlue);
    button_list->exit_text = set_text("EXIT", 50, 1760, 10);
    button_list->play_button = init_button(create_sfvector2f(700, 500)
    , create_sfvector2f(500, 80), sfRed);
    button_list->play_text = set_text("PLAY", 80, 860, 490);
    button_list->rules_button = init_button(create_sfvector2f(700, 700)
    , create_sfvector2f(500, 80), sfRed);
    button_list->rules_text = set_text("RULES", 80, 855, 690);
    button_list->level1_button = init_button(create_sfvector2f(700, 400)
    , create_sfvector2f(500, 80), sfRed);
    init_level_menu_button(button_list);
    init_gamebutton(button_list);
    init_pause_menu_button(button_list);
    return (button_list);
}