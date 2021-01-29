/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

struct square *struct_square_init(void)
{
    struct square *var = malloc(sizeof(struct square));

    if (var == NULL) {
        write(2, "malloc var faild", 17);
        exit(84);
    }
    var->y = 0;
    var->x = 0;
    var->width = 0;
    var->lenght = 0;
    var->find = 0;
    return (var);
}

int main(int ac, char **av)
{
    char ** map;
    int nbr_line;
    int *pnbr_line = &nbr_line;
    int nbr_col = 0;
    int *pnbr_col = &nbr_col;

    error_handling(av[1]);
    map = read_map(av[1], pnbr_line, pnbr_col);
    find_square(map, pnbr_col, pnbr_line);
    for (int i = 0; i < nbr_line; ++i) {
        put_str(map[i]);
        free(map[i]);
    }
    free(map); 
}