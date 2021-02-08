/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 03
*/

#include <stdio.h>
#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"

void     compareAndDivide(Object *a, Object *b)
{
    if (gt(a, b))
        printf ("a > b\n");
    else if (lt(a, b))
        printf ("a < b\n");
    else
        printf ("a == b\n");
    printf ("b / a = %s\n", str(division(b, a)));
}

int         main(void)
{
    Object  *i1 = new(Int, 12);
    Object  *i2 = new(Int, 12);

    compareAndDivide(i1, i2);
    printf("%s + %s = %s\n", str(i1), str(i2), str(addition(i1, i2)));
    printf("%s - %s = %s\n", str(i1), str(i2), str(subtraction(i1, i2)));

    Object  *f1 = new(Float, 1.5);
    Object  *f2 = new(Float, 4);

    compareAndDivide(f1, f2);
    printf("%s + %s = %s\n", str(f1), str(f2), str(addition(f1, f2)));
    printf("%s - %s = %s\n", str(f1), str(f2), str(subtraction(f1, f2)));

    Object  *v1 = new(Char, 'c');
    Object  *v2 = new(Char, 't');

    compareAndDivide(v1, v2);
    printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));

    return (0);
}