/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** display all the possible values of
an int
*/
void my_putchar(char c)
{
    write (1, &c, 1);
}

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
        my_putchar (char_print);
        end = end - 1;
    }
}

void display()
{
    display_nbr(214748364,9);
    my_putchar('8');
}

void my_put_nbr (int nb)
{
    int count;
    int nb_bis;
    int except = 0;

    if (nb == -2147483648)
        except = 1;       
    if (nb < 0) {
        my_putchar ('-');
        nb = nb * -1;
        if (nb == -2147483648)
            display();
    }
    if (nb == 0)
        my_putchar ('0');
    if (except == 0){
        count = count_nbr (nb);
        display_nbr (nb,count);
        nb_bis = nb;
    }
}

int main (void)
{
    my_put_nbr(-2147483648);
}
