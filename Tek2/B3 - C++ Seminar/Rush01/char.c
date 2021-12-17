/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char value;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Can't construct.");
    this->value = (char)(va_arg(*args, int));
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        raise("Can't destroy");
}

static to_string_t Char_str(CharClass *this)
{
    char *str_value = NULL;

    if (!this)
        raise("Can't print.");
    asprintf(&str_value, "<Char (%c)>", this->value);

    return ((to_string_t)str_value);
}

static binary_operator_t Char_add(CharClass *a, CharClass *b)
{
    if (!a || !b)
        return (NULL);

    return (new(Char, a->value + b->value));
}

static binary_operator_t Char_sub(CharClass *a, CharClass *b)
{
    if (!a || !b)
        return (NULL);

    return (new(Char, a->value - b->value));
}

static binary_operator_t Char_mul(CharClass *a, CharClass *b)
{
    if (!a || !b)
        return (NULL);

    return (new(Char, a->value * b->value));
}

static binary_operator_t Char_div(CharClass *a, CharClass *b)
{
    if (!a || !b)
        return (NULL);

    return (new(Char, a->value / b->value));
}

static binary_comparator_t Char_eq(CharClass *a, CharClass *b)
{
    if (!a || !b)
        return ((binary_comparator_t)false);
    if (a->value == b->value)
        return ((binary_comparator_t)true);

    return ((binary_comparator_t)false);
}

static binary_comparator_t Char_gt(CharClass *a, CharClass *b)
{
    if (!a || !b)
        return ((binary_comparator_t)false);
    if (a->value > b->value)
        return ((binary_comparator_t)true);

    return ((binary_comparator_t)false);
}

static binary_comparator_t Char_lt(CharClass *a, CharClass *b)
{
    if (!a || !b)
        return ((binary_comparator_t)false);
    if (a->value < b->value)
        return ((binary_comparator_t)true);

    return ((binary_comparator_t)false);
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .value = 0
};

const Class   *Char = (const Class *)&_description;