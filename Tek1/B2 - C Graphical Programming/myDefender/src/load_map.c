/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** load_map
*/

#include "my_defender.h"

int load_map_mid(int i, int fd, char ***construction_tab,
sprite_list_t **sprite_list)
{
    char *text_map = get_line(fd);;
    char *id = malloc(sizeof(char) * 2);

    id[1] = '\0';
    (*construction_tab)[i] = malloc(sizeof(char) * 16);
    if (id == NULL || (*construction_tab)[i] == NULL)
            return (1);
    for (int j = 0; j < 16; ++j) {
        id[0] = text_map[j];
        *sprite_list = add_sprite_to_sprite_list(*sprite_list,
        concat_str(concat_str("PNG/Retina/towerDefense_tile", id),
        ".png"), i, j);
        if (text_map[j] == 'a')
            (*construction_tab)[i][j] = (char)1;
        else if (text_map[j] == 'c')
            (*construction_tab)[i][j] = (char)0;
        else
            (*construction_tab)[i][j] = (char)3;
    }
    free(id);
    free(text_map);
}

sprite_list_t *load_map(char *filepath, char ***construction_tab)
{
    int fd = open(filepath, O_RDONLY);
    sprite_list_t *sprite_list = init_sprite_list();

    if (!sprite_list)
        return (NULL);
    *construction_tab = malloc(sizeof(char *) * 10);
    if (construction_tab == NULL)
        return (NULL);
    for (int i = 0; i < 9; ++i)
        load_map_mid(i, fd, construction_tab, &sprite_list);
    return (sprite_list);
}