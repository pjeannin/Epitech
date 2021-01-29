/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** add_defense
*/

#include "my_defender.h"

int add_defense(int new_defense, defender_t *defender, sfVector2f clic_pos)
{
    while (defender->defense_list->next)
        defender->defense_list = defender->defense_list->next;
    if ((clic_pos.y / 128) <= 0 || (clic_pos.y / 128) > 9
    || (clic_pos.x / 128) <= 0 || (clic_pos.x / 128) > 16)
        return (0);
    if (defender->current_mapconstruction[(int)(clic_pos.y / 128)]
    [(int)(clic_pos.x / 128)] != (char)0) {
        if (defender->defense_list->defnse != NULL) {
            defender->defense_list->next = malloc(sizeof(defense_list_t));
            defender->defense_list->next->prev = defender->defense_list;
            defender->defense_list->next->next = NULL;
            defender->defense_list = defender->defense_list->next;
        }
        if ((defender->defense_list->defnse = create_defense(new_defense,
        (int)(clic_pos.x / 128), (int)(clic_pos.y / 128))) == NULL)
            return (1);
        defender->money -= new_defense;
        return (0);
        if (defender->defense_list->next == NULL)
            return (1);
    }
    return (new_defense);
}
