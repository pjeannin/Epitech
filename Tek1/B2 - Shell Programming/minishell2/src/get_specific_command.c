/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** get_scecific_command
*/

void get_specific_command(char *command, int *pipe, int *redirect,
int *multiple)
{
    for (int i = 0; command[i]; ++i)
        switch (command[i]) {
            case '|': {
                *pipe = 1;
                break;
            } case '<': {
                *redirect = 1;
                break;
            } case '>': {
                *redirect = 1;
                break;
            } case ';': {
                *multiple = 1;
            }
        }
}