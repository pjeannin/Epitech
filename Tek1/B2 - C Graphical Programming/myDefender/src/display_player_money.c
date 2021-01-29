/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** dipslay_player_money
*/

#include "my_defender.h"

void display_player_money(defender_t *defender)
{
    picture_t *coin = init_image("PNG/coin.png", 0, 30, 5);
    sfText *money = set_text(char_from_int(defender->money), 100, 150, 0);
    sfText *score_text = set_text("SCORE :", 100, 300, 0);
    sfText *score = set_text(char_from_int(defender->score), 100, 680, 0);

    sfRenderWindow_drawSprite(defender->window, coin->sprite, sfFalse);
    sfRenderWindow_drawText(defender->window, money, sfFalse);
    sfRenderWindow_drawText(defender->window, score, sfFalse);
    sfRenderWindow_drawText(defender->window, score_text, sfFalse);
    sfText_destroy(money);
    sfText_destroy(score);
    sfText_destroy(score_text);
    free_picture(coin);
}