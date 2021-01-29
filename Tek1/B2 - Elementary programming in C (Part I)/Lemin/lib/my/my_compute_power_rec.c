/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** power rec
*/

int my_compute_power_rec(int nb, int power)
{
    if (nb == 0) {
        return (1);
    }
    if (power < 0) {
        return (0);
    }
    power--;
    nb = nb * my_compute_power_rec(nb, power - 1);
    return (nb);
}
