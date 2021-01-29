/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

int count_str(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)) {
            count += 1;
        }
        i++;
    }
    return (count);
}