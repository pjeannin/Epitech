/*
** EPITECH PROJECT, 2019
** test_my_revstr.c
** File description:
** test my_revstr
*/
#include <criterion/criterion.h>

char *my_revstr (char *str);

Test(my_revstr, test1)
{
    char test[4] = "abc";

    my_revstr(test);
    cr_assert_str_eq(test,"cba");
}

Test(my_revstr, test2)
{
    char test[8] = "epitech";

    my_revstr(test);
    cr_assert_str_eq(test,"hcetipe");
}
