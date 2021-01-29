/*
** EPITECH PROJECT, 2019
** rush3.c
** File description:
** displays the assignment's name
*/

#include<unistd.h>

int first_char(char *);
void my_put_nbr(int);
void my_putchar(char);
void my_putstr(char *);

void count_len(char *str, int *lenght, int*width)
{
    int i = 1;
    *lenght = 0;
    *width = 1;

    while (str[i] != '\n') {
        ++(*width);
        ++i;
    }
    while (str[i] != '\0') {
        if (str[i] == '\n')
            ++(*lenght);
	++i;
    }
}

void print(char *str, int *width, int *lenght)
{
    my_putstr(str);
    my_put_nbr(*width);
    my_putchar(' ');
    my_put_nbr(*lenght);
}

void print_rushV2(int nb_rush, int *width, int*lenght)
{
    switch(nb_rush) {
    case 5: {
        print("[rush1-5] ", width, lenght);
        return;
    }
    case 6: {
        print("[rush1-3] ", width, lenght);
        print(" || [rush1-4] ", width, lenght);
        print(" || [rush1-5] ", width, lenght);
        return;
    }
    }
}
 

void print_rush(int nb_rush, int *width, int*lenght)
{
    switch(nb_rush) {
    case 1: {
        print("[rush1-1] ", width, lenght);
        return;
    }
    case 2: {
        print("[rush1-2] ", width, lenght);
        return;
    }
    case 3: {
        print("[rush1-3] ", width, lenght);
        return;
    }
    case 4: {
        print("[rush1-4] ", width, lenght);
        return;
    }
    }
    print_rushV2(nb_rush, width, lenght);
}
  
int rush3(char *str)
{
    int nb_rush;
    int lenght;
    int width;
    int *plenght = &lenght;
    int *pwidth = &width;

    if (str[0] == 'I')
        return (84);
    if (str[0] != '/' && str[0] != 'A' && str[0] != 'B'
	&& str[0] != '*' && str[0] != 'o')
        return (84);
    nb_rush = first_char(str);
    count_len(str, plenght, pwidth);
    print_rush(nb_rush, pwidth, plenght);
    return (0);
}
