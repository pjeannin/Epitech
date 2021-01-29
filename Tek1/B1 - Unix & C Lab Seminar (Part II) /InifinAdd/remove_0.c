/*
** EPITECH PROJECT, 2019
** remove_0.c
** File description:
** inf add
*/

void remov_0(char *res)
{
    int i;

    while(res[0] == '0' && res[1] != '\0') {
        i = 0;
        while (res[i] != '\0') {
            res[i] = res[i + 1];
            ++i;
        }
    }
}