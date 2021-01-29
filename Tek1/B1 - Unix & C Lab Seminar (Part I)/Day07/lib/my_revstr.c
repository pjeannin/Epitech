/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** reverse a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int count_left = 0;
    int count_right;
    char swip;
    char swip_2;

    count_right = my_strlen(str) -1;
    while (count_left <= count_right) {
        swip = str[count_left];
        swip_2 = str[count_right];
        str[count_left] = swip_2;
        str[count_right] = swip;
        count_left += 1;
        count_right -= 1;
    }
    str[my_strlen(str)] = '\0';
    return (str);
}
