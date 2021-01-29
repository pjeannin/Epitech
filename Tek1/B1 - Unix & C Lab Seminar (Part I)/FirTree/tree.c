/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** a function that displays a fir tree, based on its given size.
*/

void trunk(int size, int len)
{
    int even = 0;
    int width;
    
    if (0 == size % 2)
        even = 1;
    width = size + even;
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j <= len / 2 - width / 2; ++j)
            my_putchar(' ');
        for (int k = 0; k < width; ++k)
            my_putchar('|');
        my_putchar('\n');
    }
}

int size_l_line(int size)
{
    int len = 7;
    int add = 6;
    
    for(int i = 1; i < size; ++i) {
        if(i % 2 == 0)
            add += 2;
        len += add;    
    }
    return (len);
}

void display_stars(int nb_spaces, int nb_stars)
{
    for (int i = 1; i <= nb_spaces; ++i) {
        my_putchar(' ');
    }
    for (int i = 1; i <= nb_stars; ++i)
        my_putchar('*'); 
}

void compute(int size, int len)
{
    int stage = 4;
    int nb_stars = 1;
    int nb_spaces = len / 2;
    int var = 1;

    for (int k = 1; k <= size; ++k) {
        for (int j = 1; j <= stage; ++j) {
            display_stars(nb_spaces, nb_stars);
            nb_stars += 2;
            nb_spaces -= 1;
            my_putchar('\n');
        }
        if (stage % 2 == 0)
            var += 1; 
        nb_stars -= var * 2;
        nb_spaces += var;
        stage += 1;
    }    
}

void tree(int size)
{
    int len;
    
    len = size_l_line(size);
    compute(size, len);
    trunk(size, len);
}
