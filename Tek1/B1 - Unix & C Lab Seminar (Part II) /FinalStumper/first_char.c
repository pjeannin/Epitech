/*
** EPITECH PROJECT, 2019
** first_char.c
** File description:
**  find the first char of a string
*/

int is_3_4_5(char *str)
{
    int i = 0;
    int count = 0;

    if (str[i] == 'A') {
        ++i;
        while (str[i]!= 'A' && str[i] != 'C') 
            ++i;
        if (str[i] == 'A')
            count = 3;
        else
            count = 4;
    }
    while ((str[i + 1] >= 65 && str[i + 1] <= 90) || (str[i + 1] >= 97 && str[i + 1] <= 122)
	   || str[i + 1] == '\n' || str[i + 1] == ' ')
        ++i;
    if (str[i - 1] == 'A')
        count = 5;
    return (count);
}  

int first_char(char *str)
{
    int count = 0;
    int i = 0;

    if (str[0] == 'o')
      count = 1;
    if (str[0] == '/' || str[0] == '*')
      count = 2;
    if (str[0] == 'B')
      count = 6;
    if (count == 0)
      count = is_3_4_5(str);
    return (count);
}
