/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02M-pierre.jeannin
** File description:
** tab_to_2dtab
*/

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int x = 0;
    int y = 0;

    *res = malloc(sizeof(int *) * length);
    for (int i = 0; i < length; ++i)
        (*res)[i] = malloc(sizeof(int) * width);
    for (int i = 0; i < length * width && tab[i]; ++i) {
        (*res)[y][x++] = tab[i];
        if (x == width) {
            ++y;
            x = 0;
        }
    }
}