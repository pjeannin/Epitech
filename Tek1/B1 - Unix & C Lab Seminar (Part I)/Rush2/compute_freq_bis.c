/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

int compute_freq_bis(char *str, int occurence)
{
    float res = 100;
    float rescpy = 0;
    int nb_letter = 0;
    int aff1 = 0;
    int aff2 = 0;

    nb_letter = count_str(str);
    res = occurence;
    res /= nb_letter;
    res *= 100;
    aff1 = res;
    return (res);
}