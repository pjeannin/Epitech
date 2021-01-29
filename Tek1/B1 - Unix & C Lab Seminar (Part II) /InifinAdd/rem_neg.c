/*
** EPITECH PROJECT, 2019
** rem_neg.c
** File description:
** inf add
*/

void rem_neg(char *av1, char *av2)
{
    for (int i = 0; av1[i]; ++i) {
        av1[i] = av1[i + 1];
    }
    for (int i = 0; av2[i]; ++i) {
        av2[i] = av2[i + 1];
    }
}