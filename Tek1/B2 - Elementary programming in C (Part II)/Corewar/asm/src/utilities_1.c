/*
** EPITECH PROJECT, 2020
** utilities_1
** File description:
** utilities_1
*/

#include "includes.h"

bool skip_flag(char **str, char const *flag, char const end, bool const end_)
{
    for (; (*str)[0] && (*str)[0] != end && 
    flag_cmp((*str)[0], flag) == end_; ++*str);
    return (((*str)[0] == end) ? (true) : (false));
}
