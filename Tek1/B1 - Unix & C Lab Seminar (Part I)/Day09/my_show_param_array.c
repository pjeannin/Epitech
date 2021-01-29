/*
** EPITECH PROJECT, 2019
** my_show_param_array.c
** File description:
** show param array
*/
#include<stdlib.h>
//#include "include/my.h"

struct info_param
{
    int lenght;
    char *str;
    char *copy;
    char **word_array;
};

struct info_param new_struct(char *param)
{
    struct info_param arg;
    arg.lenght = my_strlen(param);
    arg.str = param;
    arg.copy = my_strdup(param);
    arg.word_array = my_str_to_worad_array(param);
    return (arg);
}

struct info_param *my_params_to_array(int ac ,char **av)
{
    struct info_param *array;

    array = malloc(sizeof(struct info_param) * ac);
    for (int i = 0; i < ac; ++i)
        array[i] = new_struct(av[i]);
    return (&array);
}

void show(struct info_param const *para)
{
    my_put_nbr((*para).lenght);
    my_putcahr('\n');
    my_putstr((*para).str);
    my_putchar('\n');
    my_show_word_array((*para).word_array);
    my_putchar('\n');
}

int show_my_param_array(struct info_param const *par)
{
    for (int i =0; par[i].str != NULL; ++i)
        show(&par[i]);
    return (0);
}

int main (int argc, char **argv)
{
    show_my_param_array(my_params_to_array(argc, argv));
}


