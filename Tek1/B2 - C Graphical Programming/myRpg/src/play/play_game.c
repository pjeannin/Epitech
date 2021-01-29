/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_game
*/

#include "my_rpg.h"

void draw_game(window_t *win, charact_t *charact, game_t *game_struct)
{
    create_rain(game_struct);
    draw_map(game_struct, win);
    draw_objects(game_struct, win, charact);
    draw_charact(charact, win);
    draw_guardian(game_struct, win);
    if (game_struct->boss.life <= 0)
        death_boss(game_struct);
    sfRenderWindow_drawSprite(win->window, game_struct->boss.sprite, sfFalse);
    guardian_damage(game_struct, charact);
    boss_damage(game_struct, charact);
}

void play_game(window_t *win, charact_t *charact, game_t *game_struct)
{
    draw_game(win, charact, game_struct);
    updtade_quete(game_struct);
    update_level(game_struct);
    display_quete(game_struct, win);
    update_guardian_life(game_struct);
    draw_echap(win);
    draw_inventory(win);
    draw_particules(game_struct, win);
    if (win->screen > 6)
        --win->screen;
    update_particules(game_struct);
    charact->has_shoot = (charact->has_shoot == 0 ? 0 : charact->has_shoot--);
    if (game_struct->player_stats.life <= 0) {
        win->die = 1;
        win->echap_switch = 1;
    }
    if (game_struct->boss.life <= 0)
        win->screen = 6;
}