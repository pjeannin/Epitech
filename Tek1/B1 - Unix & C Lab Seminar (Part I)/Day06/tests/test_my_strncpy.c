/*
** EPITECH PROJECT, 2019
** test_my_strncpy.c
** File description:
** test my_strncpy.c
*/
#include <criterion/criterion.h>

char *my_strncpy(char *dest, char *src, int n);

Test(my_strncpy, test_2_my_strcpy)
{
    char dest[5];
    char dest2[5];

    my_strncpy(dest, "Main", 3);
    strncpy(dest2, "Main", 3);
    cr_assert_str_eq("Mai", dest2);
}

Test(my_strncpy, test3)
{
    char dest [11];
    char my_dest [11];
    
    my_strncpy(my_dest , "HelloWorld", 6);
    cr_assert_str_eq ("HelloW" , "HelloW") ;
}

