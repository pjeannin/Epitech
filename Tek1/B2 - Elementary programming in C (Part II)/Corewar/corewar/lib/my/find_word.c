/*
** EPITECH PROJECT, 2019
** find_word
** File description:
** find Xth word position
*/

int find_word(char *line, int which)
{
    int i = 0;

    --which;
    if (which <= 0)
        return (0);
    for (int j = 0; j < which; ++j) {
        while (line[i] == 32)
            ++i;
        while (line[i] != 32)
            ++i;
    }
    return (i);
}
