/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void end_event(window_t *win, game_t *game_struct)
{
    if (win->screen != 6)
        return;
    if (win->event.key.type == sfEvtKeyPressed
    && (win->event.key.code == sfKeyE || win->event.key.code == sfKeyA
    || win->event.key.code == sfKeyQ)) {
        if (win->event.key.code == sfKeyQ) {
            sfRenderWindow_close(win->window);
        } else if (win->event.key.code == sfKeyA) {
            win->screen = 1;
        } else {
            game_struct->boss.life = 1;
            game_struct->boss.pos = (sfVector2f){678765, 876789};
            sfSprite_setPosition(game_struct->boss.sprite,
            game_struct->boss.pos);
            win->screen = 2;
        }
    }
}