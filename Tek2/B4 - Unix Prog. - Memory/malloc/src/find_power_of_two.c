/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-malloc-pierre.jeannin
** File description:
** find_power_of_two
*/

int my_pow(int number, int power)
{
    int return_value = number;

    for (; power > 0; --power)
        return_value *= number;

    return (return_value);
}

int find_upper_power_of_two(int number)
{
    int return_value = 0;

    for (int i = 0; number > return_value; ++i)
        return_value = my_pow(2, i);

    return (return_value);
}