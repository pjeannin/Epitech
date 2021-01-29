/*
** EPITECH PROJECT, 2019
** my_params_to_array.c
** File description:
** create a param array
*/

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
    return (array);
}