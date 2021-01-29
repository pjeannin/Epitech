/*
** EPITECH PROJECT, 2019
** rush1-2.c
** File description:
** display squares
*/


void exception (int x, int y)
{
    if (x > 1) {
        for (int i = 1; i <= x; ++i)
            my_putchar ('*');
    } else {
        for (int i = 1; i <= 2; ++i) {
            my_putchar ('*');
            my_putchar ('\n');
        }
    }
}

void last_line (int x)
{
    for (int j = 1; j < x; ++j) {
        if (1 == j || x == j)
            my_putchar ('\\');
        else
            my_putchar ('*');
    }
    my_putchar ('/');
    my_putchar ('\n');
}

int first_line (int x, int y)
{
    int k = 0;
    
    if (x > 1 && y > 1) {
        k = 1;
        for (int j = 1; j < x; ++j) {
            if (1 == j || x == j)
                my_putchar ('/');
            else
                my_putchar ('*');
        }
        my_putchar ('\\');
        my_putchar ('\n');
    }
    return (k);
}

int invalid_output (int x, int y)
{
    if (x <= 0 || y <= 0 || x > 2147483647 || y > 2147483647)
    {
        write(2, "Invalid size\n", 14);
        return (0);
    }
    return (1);
}

void rush (int x, int y)
{
    int k = 0;
    int size;
    
    size = invalid_output(x, y);
    if (size == 0)
        return;
    k = first_line (x, y);
    if (k == 0)
        exception(x,y);
    for (int i = 2; i < y; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (1 == j || x == j)
                my_putchar ('*');
            else
                my_putchar (' ');
        }
        my_putchar ('\n');
    }
    if (k == 1)
        last_line (x);
}
