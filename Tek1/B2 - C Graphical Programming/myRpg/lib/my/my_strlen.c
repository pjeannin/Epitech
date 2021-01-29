/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** strlen
*/

int my_strlen(char const *str)
{
    int k = 0;

    while (str[k] != '\0') {
        k++;
    }
    return (k);
}
