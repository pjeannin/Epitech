/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** find_pipe_start
*/

int find_pipe_start(char **input)
{
    for (int i = 0; input[i]; ++i)
        for (int j = 0; input[i][j]; ++j)
            if (input[i][j] == '#') {
                ++i;
                j = 0;
            } else if (input[i][j] == '-')
                return (i);
    return (-1);
}