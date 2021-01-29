/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_score
*/

#include "my_defender.h"

void display_score(defender_t *defender)
{
    sfText *score = set_text(char_from_int(defender->score), 110, 960 -
    ((str_len(char_from_int(defender->score)) * 60) / 2), 700);
    sfText *best_score_text = set_text("BEST SCORE", 200, 500, 200);
    sfText *your_score = set_text("YOUR SCORE", 150, 600, 500);
    sfText *hscore_t = set_text("HIGH SCORE", 70, 300, 0);
    sfText *hscore = set_text(char_from_int(defender->high_score), 70, 750, 0);

    sfRenderWindow_drawText(defender->window, score, sfFalse);
    if (defender->score > defender->high_score)
        sfRenderWindow_drawText(defender->window, best_score_text, sfFalse);
    sfRenderWindow_drawText(defender->window, hscore, sfFalse);
    sfRenderWindow_drawText(defender->window, hscore_t, sfFalse);
    sfRenderWindow_drawText(defender->window, your_score, sfFalse);
    sfText_destroy(score);
    sfText_destroy(best_score_text);
    sfText_destroy(your_score);
    sfText_destroy(hscore_t);
    sfText_destroy(hscore);
}