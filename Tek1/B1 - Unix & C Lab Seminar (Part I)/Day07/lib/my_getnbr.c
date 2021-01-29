/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** Write a function that returns a number, sent to the function as a string
*/

int count_nbr(int nb)
{
    int nb_bis;
    int count = 0;

    nb_bis = nb;
    while (nb_bis != 0) {
        nb_bis = nb_bis / 10;
        count = count + 1;
    }
    return (count);
}
    

void display_nbr(int nb,int count)
{
    char char_print;
    int end;
    int nb_bis;

    end = count - 1;
    for (int k = 0;k != count;k++) {
        nb_bis = nb;
        for (int i = 0;i != end;i++) {
            nb_bis = nb_bis / 10;
        }
        char_print = nb_bis % 10 + 48;
        my_putchar(char_print);
        end = end - 1;
    }
}

void display()
{
    display_nbr(214748364,9);
    my_putchar('8');
}

void my_put_nbr(int nb)
{
    int count;
    int nb_bis;
    int except = 0;

    if (nb == -2147483648)
        except = 1;       
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        if (nb == -2147483648)
            display();
    }
    if (nb == 0)
        my_putchar('0');
    if (except == 0){
        count = count_nbr(nb);
        display_nbr(nb,count);
        nb_bis = nb;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int res = 0;
    int count_len_nbr = 0;
    int count_neg = 0;
    int is_neg = 1;

    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == 45)
            ++count_neg;
        ++i;
    }
    if (count_neg % 2 == 1)
        is_neg = -1;
    while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9') {
        res *= 10;
        res += str[i] - 48;
        ++i;
        ++count_len_nbr;
        my_put_nbr(count_len_nbr);
        if (count_len_nbr > 10)
            return (0);
    }
    res *= is_neg;
    return (res);
}
