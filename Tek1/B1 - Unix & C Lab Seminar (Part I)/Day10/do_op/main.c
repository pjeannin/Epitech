/*
** EPITECH PROJECT, 2019
** do-op
** File description:
** main
*/
int my_getnbr(char *);
void my_put_nbr(int);
void my_putchar(char);
void my_putstr(char *);

struct operator
{
    char ope;
    int (*fptr)(char *, char *);
};

int my_add(char *nb, char *nb_bis) {
    int res;
    int nb1;
    int nb2;

    nb1 = my_getnbr(nb);
    nb2 = my_getnbr(nb_bis);
    res = nb1 + nb2;
    my_put_nbr(res);
    return (1);
}

int my_sub(char *nb, char *nb_bis) {
    int res;
    int nb1;
    int nb2;

    nb1 = my_getnbr(nb);
    nb2 = my_getnbr(nb_bis);
    res = nb1 - nb2;
    my_put_nbr(res);
    return (1);
}

int my_div(char *nb, char *nb_bis) {
    int res;
    int nb1;
    int nb2;

    nb1 = my_getnbr(nb);
    nb2 = my_getnbr(nb_bis);
    if (nb2 == 0) {
        my_putstr("Stop: division by zero");
        return (84);
    }
    res = nb1 / nb2;
    my_put_nbr(res);
    return (1);
}

int my_mul(char *nb, char *nb_bis) {
    int res;
    int nb1;
    int nb2;

    nb1 = my_getnbr(nb);
    nb2 = my_getnbr(nb_bis);
    res = nb1 * nb2;
    my_put_nbr(res);
    return (1);
}

int my_mod(char *nb, char *nb_bis) {
    int res;
    int nb1;
    int nb2;

    if (nb2 == 0) {
        my_putstr("Stop: modulo by zero");
        return (84);
    }
    nb1 = my_getnbr(nb);
    nb2 = my_getnbr(nb_bis);
    res = nb1 % nb2;
    my_put_nbr(res);
    return (1);
}

int main (int argc, char **argv)
{
    int ok = 0;
    struct operator OPERATORS_FUNCS[] = {{'+', &my_add}, {'-', &my_sub},
    {'/', &my_div}, {'*', &my_mul}, {'%', &my_mod}};

    if (argc != 4) {
        my_putchar('0');
        return (84);
    }
    for (int i = 0; i < argc; ++i) {
        if (argv[2][0] == OPERATORS_FUNCS[i].ope)
            ok = OPERATORS_FUNCS[i].fptr(argv[1], argv[3]);
    }
    if (ok == 0)
        my_putchar('0');
        return (84);
    return (0);
};