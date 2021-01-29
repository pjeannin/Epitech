/*
** EPITECH PROJECT, 2019
** my_find_prime_sup.c
** File description:
** find sup prime number
*/

int my_find_prime_sup (int nb)
{
    int res = nb;
    int count = 0;

    for(int i = 1; i <= nb; ++i) {
        if (nb % i == 0)
            ++ count;
    }
    if (count == 2)
        return (res);
    else
        my_find_prime_sup (nb + 1);
        
}
