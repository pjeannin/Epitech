/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

static void guardian(game_t *game_struct, int i, window_t *win,
charact_t *charact)
{
    if (game_struct->guardian[i].isalave && !charact->has_shoot
    && charact->charact_pos.x > game_struct->guardian[i].pos.x - 20
    && charact->charact_pos.x < game_struct->guardian[i].pos.x + 180
    && charact->charact_pos.y > game_struct->guardian[i].pos.y - 20
    && charact->charact_pos.y < game_struct->guardian[i].pos.y + 180) {
        if (win->event.key.code == sfKeyA) {
            game_struct->guardian[i].life -= 10
            * game_struct->player_stats.level;
            game_struct->player_stats.life -= 3;
        } else if (win->event.key.code == sfKeyR
        && game_struct->object_list[0].istake
        && !game_struct->object_list[0].isused) {
            game_struct->guardian[i].life -= 40
            * game_struct->player_stats.level;
            game_struct->player_stats.life -= 3;
        }
        create_partiules(game_struct, game_struct->guardian[i].pos.x,
        game_struct->guardian[i].pos.y + 160);
    }
}

static void boss(game_t *game_struct, window_t *win, charact_t *charact)
{
    if (game_struct->boss.isalave && !charact->has_shoot
    && charact->charact_pos.x > game_struct->boss.pos.x
    && charact->charact_pos.x < game_struct->boss.pos.x + 450
    && charact->charact_pos.y > game_struct->boss.pos.y
    && charact->charact_pos.y < game_struct->boss.pos.y + 450) {
        if (win->event.key.code == sfKeyA) {
            game_struct->boss.life -= 10
            * game_struct->player_stats.level;
            game_struct->player_stats.life -= 3;
        } else if (win->event.key.code == sfKeyR
        && game_struct->object_list[0].istake
        && !game_struct->object_list[0].isused) {
            game_struct->boss.life -= 40
            * (game_struct->player_stats.level / 2);
            game_struct->player_stats.life -= 3;
        }
        create_partiules(game_struct, game_struct->boss.pos.x + 150,
        game_struct->boss.pos.y + 400);
    }
}

void player_damage(game_t *game_struct, charact_t *charact, window_t *win)
{
    if ((win->event.key.code == sfKeyA || win->event.key.code == sfKeyR)
    && win->event.key.type == sfEvtKeyPressed) {
        for (int i = 0; i < 4; ++i)
            guardian(game_struct, i, win, charact);
        boss(game_struct, win, charact);
    }
}