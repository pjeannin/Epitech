/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "lemin.h"
#include "error_handling.h"
#include "my.h"
#include "load_infos.h"
#include "display_start_infos.h"
#include "load_graph.h"
#include "resolver.h"

int main(int ac, char **av)
{
    char **input = error_handling(ac, av);
    lemin_t *lemin_struct;

    if (!input)
        return (84);
    lemin_struct = load_infos(input);
    if (lemin_struct < 0)
        return (84);
    load_graph(lemin_struct, input);
    display_start_infos(input);
    resolve(lemin_struct);
    return (0);
}