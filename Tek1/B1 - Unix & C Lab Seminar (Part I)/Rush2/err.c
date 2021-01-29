/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

int err(int argc, char **argv)
{
    if (argc < 3)
        return (84);
    for (int i = 2; i < argc; ++i)
        if (is_alpha(argv[i][0]) != 1 || argv[i][1] != '\0')
            return (84);
    return (0);
}