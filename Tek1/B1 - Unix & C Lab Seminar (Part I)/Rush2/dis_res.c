/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

void dis_res(int *count_g, int *count_s, int *count_f, int *count_e)
{
    if (*count_g > *count_s && *count_g > *count_f && *count_g > *count_e)
        my_putstr("=>German");
    if (*count_s > *count_g && *count_s > *count_f && *count_s > *count_e)
        my_putstr("=>Spanish");
    if (*count_f > *count_s && *count_f > *count_g && *count_f > *count_e)
        my_putstr("=>French");
    if (*count_e > *count_s && *count_e > *count_f && *count_e > *count_g)
        my_putstr("=>English");
}