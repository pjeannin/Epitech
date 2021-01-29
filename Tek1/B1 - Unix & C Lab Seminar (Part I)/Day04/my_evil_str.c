/*
** EPITECH PROJECT, 2019
** my_evil_str.c
** File description:
** swap each of the string’s characters, two by two.
*/

char *my_evil_str (char *str)
{
    int count_left = 0;
    int count_right;
    char swip;
    char swip_2;

    count_right = my_strlen(str);
    while(count_left<count_right) {
        swip = str[count_left];
        swip_2 = str[count_right];
        str[count_left] = swip_2;
        str[count_right] = swip;
        count_left += 1;
        count_right -= 2;
    }
    return (str);
}
