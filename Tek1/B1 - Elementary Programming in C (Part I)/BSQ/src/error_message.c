/*
** EPITECH PROJECT, 2019
** error_message.c
** File description:
** bsq
*/

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void error_message(char *str)
{
    write(2, str, str_len(str));
    exit(84);
}