/*
** EPITECH PROJECT, 2019
** my_is_prime.c
** File description:
** return if number is a prime number
*/

int my_is_prime(int nb)
{
    int count = 0;

    for (int i = 1; i <= nb; ++i) {
        if (nb % i == 0) 
            ++count;
    }
    if (count == 2)
        return (1);
    else
        return (0);
}
