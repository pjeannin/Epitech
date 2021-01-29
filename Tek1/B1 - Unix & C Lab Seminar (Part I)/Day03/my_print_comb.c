/*
** EPITECH PROJECT , 2019
** my_print_comb.c
** File description :
** displays, in ascending order, all the numbers composed by three different digits number*/
#include <unistd.h>

int incrementing_digit_3 (char digit_3)
{
    if (digit_3<57)
        digit_3++;
    else
        digit_3=48;
    return (digit_3);
}

int incrementing_digit_2 (char digit_2 , char digit_3)
{
    if (digit_3==48 && digit_2!=57)
        digit_2++;
    if (digit_3==48 && digit_2==57)
        digit_2=48;
    return (digit_2);
}

int incrementing_digit_1 (char digit_1 , char digit_2 , char digit_3)
{
    if (digit_2==48 && digit_3==48)
        digit_1++;
    return (digit_1);
}

int display (char digit_1 , char digit_2 , char digit_3 , int i)
{
    if (digit_1 < digit_2 && digit_2 < digit_3) {
        int sum;
        my_putchar (digit_1);
        my_putchar (digit_2);
        my_putchar (digit_3);
        sum = digit_1 + digit_2 + digit_3;
        if (sum<168) {
            my_putchar (',');
            my_putchar (' ');
	}
    }
}

int my_print_comb ( void )
{
    char digit_1 = 48;
    char digit_2 = 48;
    char digit_3 = 57;
  
    for(int i = 0 ; i < 719 ; i++) {
        display(digit_1 , digit_2 , digit_3 , i);
        digit_3 = incrementing_digit_3 (digit_3);
        digit_2 = incrementing_digit_2 (digit_2 , digit_3);
        digit_1 = incrementing_digit_1 (digit_1 , digit_2 , digit_3);
    }
    return (0);
}
