/*
** EPITECH PROJECT, 2019
** rush1-1.c
** File description:
** display sqaures
*/
  
void first_last_line (int x)
{
    for (int j = 1; j <= x; ++j) {
        if (1 == j || x == j)
            my_putchar ('O');
        else
            my_putchar ('-');
    }
    my_putchar ('\n');
}

void print_line (int x, int j)
{
    if (1 == j || x == j)
        my_putchar ('|');
    else
        my_putchar (' ');
}

int invalid_output (int x, int y)
{
    if (x <= 0 || y <= 0 || x > 2147483647 || y >= 2147483647) {
        write(2, "Invalid size\n", 14);
        return (0);
    }
    return (1);
}

void rush (int x, int y)
{
    int j;
    int size;

    size = invalid_output(x,y);
    if (size == 0)
        return;
    first_last_line (x);
    for (int i = 2; i < y; ++i) {
        for (int j = 1; j <= x; ++j) {
            print_line (x, j);
        }
        my_putchar ('\n');
    }
    first_last_line (x);
}
