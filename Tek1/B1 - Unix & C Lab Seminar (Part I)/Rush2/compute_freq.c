/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

int compute_freq(char *str, char letter, int occurence)
{
    float res = 100;
    int nb_letter = 0;
    int aff1 = 0;

    nb_letter = count_str(str);
    res = occurence;
    res /= nb_letter;
    res *= 100;
    aff1 = res;
    my_putchar('(');
    my_put_nbr(aff1);
    my_putchar('.');
    aff1 = (res - aff1) * 100;
    my_put_nbr(aff1);
    if (aff1 == 0)
        my_put_nbr(aff1);
    my_putstr("%)");
    my_putchar('\n');
    return (aff1);
}