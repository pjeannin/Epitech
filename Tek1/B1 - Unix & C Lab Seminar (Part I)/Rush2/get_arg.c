/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

void get_arg(int argc, char **argv)
{
    struct letter current[argc];

    current[i].letter = argv[i][0];
    current[i].occ = nbr_letter(argv[1], current[i].letter);
    current[i].freq = compute_freq(argv[1], argv[i][0], current[i].occ);
}