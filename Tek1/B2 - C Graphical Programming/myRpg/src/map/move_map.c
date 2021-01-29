/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

static sfVector2f pos_map(game_t *game_struct)
{
    sfVector2f pos = {0, 0};

    switch (game_struct->map->anim) {
        case 1:
            pos.y -= MAP_SPEED;
            break;
        case 2:
            pos.x += MAP_SPEED;
            break;
        case 3:
            pos.x -= MAP_SPEED;
            break;
        case 4:
            pos.y += MAP_SPEED;
            break;
        default:
            break;
    }
    return (pos);
}

static void move_guardian_pos(game_t *game_struct, sfVector2f pos)
{
    for (int i = 0; i < 4; ++i)
        set_guardian_pos(game_struct, i, (sfVector2f){
        game_struct->guardian[i].pos.x + pos.x, game_struct->guardian[i].pos.y
        + pos.y});
}

void move_map(game_t *game_struct)
{
    sfVector2f pos;
    sfVector2f changing_pos;

    pos = pos_map(game_struct);
    changing_pos = sfSprite_getPosition(game_struct->map->map);
    changing_pos.x += pos.x;
    changing_pos.y += pos.y;
    sfSprite_setPosition(game_struct->map->map, changing_pos);
    for (int i = 0; i < 4; ++i) {
        game_struct->object_list[i].pos = (sfVector2f){sfSprite_getPosition(
            game_struct->object_list[i].sprite).x + pos.x,
        sfSprite_getPosition(game_struct->object_list[i].sprite).y + pos.y};
        sfSprite_setPosition(game_struct->object_list[i].sprite,
        game_struct->object_list[i].pos);
    }
    game_struct->boss.pos = (sfVector2f){game_struct->boss.pos.x + pos.x,
    game_struct->boss.pos.y + pos.y};
    sfSprite_setPosition(game_struct->boss.sprite, game_struct->boss.pos);
    move_guardian_pos(game_struct, pos);
}