/*
** EPITECH PROJECT, 2019
** my_struppercase.c
** File description:
** every letter of a string in uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}