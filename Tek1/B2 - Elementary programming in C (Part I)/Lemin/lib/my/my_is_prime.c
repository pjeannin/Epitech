/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** isprime
*/

int my_is_prime(int nb)
{
    int a = 2;

    if (nb <= 0) {
        return (0);
    }
    while (nb % a > 0) {
        a++;
        if (a == nb) {
            return (1);
        }
    }
    return (0);
}
