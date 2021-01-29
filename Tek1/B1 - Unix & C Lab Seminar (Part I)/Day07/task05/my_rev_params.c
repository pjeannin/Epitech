/*
** EPITECH PROJECT, 2019
** my_rev_params.c
** File description:
** display rev param
*/

int main (int argc, char **argv)
{
    for (int i = argc - 1 ; 0 <= i; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
