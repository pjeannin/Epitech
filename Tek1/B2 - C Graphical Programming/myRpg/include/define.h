/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define NEED_NO_ARGS "My_RPG don't need arguments.\n"
#define MAP_READ_ERROR "Une erreur est survenue lors de la lecture de la map.\n"
#define INVALID_MAP "La map n'est pas valide.\n"
#define RPG_ERROR "My_rpg has encountered an error.\n"
#define ASK_FIRST_QUETE "Voici votre premiere quete, trouvez la dague pour combatre le chef ..."
#define DONE_FIRST_QUETE "Bien joue, avec cette dague vous pouvez elimiez lee chef !"
#define ASK_SEC_QUETE "Maintenant equipe, à toi de tuer le chef des gardes ..."
#define DONE_SEC_QUETE "Parfait, quel bon travail, maintenant promene toi tu as fini le jeu"
#define MAP_LEFT (sfSprite_getPosition(game_struct->map->map).x)
#define MAP_TOP (sfSprite_getPosition(game_struct->map->map).y)
#define MAP_RIGHT (sfSprite_getPosition(game_struct->map->map).x + 3200 * 2)
#define MAP_BOTTOM (sfSprite_getPosition(game_struct->map->map).y + 3200 * 2)
#define R 0
#define G 1
#define B 2
#define A 3
#define MAP_SPEED 12

#endif /* !DEFINE_H_ */
