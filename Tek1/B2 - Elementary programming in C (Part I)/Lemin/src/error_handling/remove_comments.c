/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** remove_comments
*/

char **remove(char **input, int i, int j)
{
    if (input[i][j] == '#' && input[i][j + 1] != '#') {
        if (j == 0) {
            input[i][j] = '\0';
        } else if (input[i][j - 1] != '#') {
            input[i][j] = '\0';
        }
    }
    return (input);
}

char **remove_comments(char **input)
{
    for (int i = 0; input[i]; ++i)
        for (int j = 0; input[i][j]; ++j)
            input = remove(input, i, j);
    return (input);
}