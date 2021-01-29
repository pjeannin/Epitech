/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_defender
*/

#include "my_defender.h"

void free_button_list_text(button_list_t *list)
{
    sfText_destroy(list->exit_text);
    sfText_destroy(list->level1_text);
    sfText_destroy(list->level2_text);
    sfText_destroy(list->level3_text);
    sfText_destroy(list->main_menu_text);;
    sfText_destroy(list->menu_text);
    sfText_destroy(list->play_again_text);
    sfText_destroy(list->play_text);
    sfText_destroy(list->restart_text);
    sfText_destroy(list->resume_text);
    sfText_destroy(list->rules_text);
}

void free_button_list(button_list_t *list)
{
    sfRectangleShape_destroy(list->exit_button->button);
    sfRectangleShape_destroy(list->level1_button->button);
    sfRectangleShape_destroy(list->level2_button->button);
    sfRectangleShape_destroy(list->level3_button->button);
    sfRectangleShape_destroy(list->main_menu_button->button);
    sfRectangleShape_destroy(list->menu_button->button);
    sfRectangleShape_destroy(list->play_again_button->button);
    sfRectangleShape_destroy(list->play_button->button);
    sfRectangleShape_destroy(list->restart_button->button);
    sfRectangleShape_destroy(list->resume_button->button);
    sfRectangleShape_destroy(list->rules_button->button);
    free_picture(list->defense1->button);
    free_picture(list->defense2->button);
    free_picture(list->pause->button);
    free_button_list_text(list);
    free(list);
}