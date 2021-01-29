/*
** EPITECH PROJECT, 2020
** set_list.c
** File description:
** runner
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Audio.h>
#include <SFML/Window/Keyboard.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_runner.h"

map_list_t *initlist(void)
{
    map_list_t *list = malloc(sizeof(map_list_t));

    list->next = NULL;
    list->prev = NULL;
    list->element = NULL;
    return (list);
}

map_list_t *add_elem(int y, int x, map_list_t *list)
{
    map_list_t *new_node = initlist();

    new_node->element = init_image("picture/bloc.png", 0, y, x);
    new_node->prev = list;
    return (new_node);
}

void init_map_list_mid(char **map_text, int i, int j, map_list_t **list)
{
    if (map_text[i][j] == '#')
        if ((*list)->element == NULL) {
            (*list)->element = init_image("picture/bloc.png", 0,
            j * 120 + 1920, i * 120);
        } else {
            (*list)->next = add_elem(j * 120 + 120, i * 120, *list);
            *list = (*list)->next;
        }
}

map_list_t *init_map_list(char *filepath, game_t *game)
{
    int nbr_line = 0;
    int nbr_col = 0;
    char **map_text = read_map(filepath, &nbr_line, &nbr_col);
    map_list_t *list = initlist();

    if (map_text == -1)
        return (-1);
    for (int i = 0; nbr_line > i; ++i)
        for (int j = 0; nbr_col > j; ++j)
            init_map_list_mid(map_text, i, j, &list);
    list = move_beginning(list);
    game->end = nbr_col * 120;
    return (list);
}