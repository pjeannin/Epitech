/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_line
*/

int check_line(char *line)
{
    int count = 0;

    for (int i = 0; line[i]; ++i)
        if (line[i] == '-')
            ++count;
    if (count != 1)
        return (-1);
    return (0);
}