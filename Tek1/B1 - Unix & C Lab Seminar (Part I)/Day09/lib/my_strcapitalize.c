/*
** EPITECH PROJECT, 2019
** my_strcapitalize.c
** File description:
** capitlize first letter of each word
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    ++i;
    while (str[i + 1] != '\0') {
        if (str[i + 1] >= 'a' && str[i] <= 'z' ) {
            if (str[i] < 48 || str[i] > 57 && str[i] < 65)
                str[i + 1] -= 32;
        }
        if (str[i] >= 65 && str[i + 1] >= 65 &&  str[i + 1] <= 90)
            str[i + 1] += 32;
        ++i;
    }
    return (str);
}
