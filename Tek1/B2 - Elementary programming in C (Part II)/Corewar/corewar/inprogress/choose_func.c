/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** choose_func
*/

#include <stdarg.h>
#include <my.h>

void cast_argument(char flag, int index, va_list args)
{
    void (*func)(void *);
    void *tab_func[] = {take_oneparams, load_params, take_twoparams,
        carry_params, sub_params, and_params, or_params, xor_params,
        zjmp_params, ldi_params, sti_params, fork_params, long_ld_params,
        long_ldi_params, long_fork_params, aff_params};

    func = tab_func[index];
    func(args);
}

void func_ptr(char flag, va_list args)
{
    char tab_flag[] = {'0x01', '0x02', '0x03', '0x04', '0x05', '0x06', '0x07',
    '0x08','0x09', '0x0a', '0x0b', '0x0c', '0x0d', '0x0e', '0x0f',
    '0x10', '\0'};

    int index = 0;

    while (tab_flag[index] != '\0') {
        if (tab_flag[index] == flag) {
            cast_argument(flag, index, args);
        }
        index++;
    }
}

int choose_func(char const *str, ...)
{
    va_list args;
    int i = 0;

    va_start(args, str);
    while (str[i] != '\0') {
        if (str[i + 1] == '%'){
            my_putchar('%');
        }
        if (str[i] == '%') {
            func_ptr(str[i + 1], args);
        }
        i++;
    }
    return (0);
}