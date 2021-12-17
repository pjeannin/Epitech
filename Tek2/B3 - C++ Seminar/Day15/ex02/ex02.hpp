/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD15-pierre.jeannin
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template <typename T>
const T &min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (a < b)
        return (a);
    else if (b < a)
        return (b);

    return (b);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a < b)
        return (a);
    if (a > b)
        return (b);

    return (b);
}

template<typename T>
const T&templateMin(const T *tab, int size)
{
    T minimum = const_cast<T&>(tab[0]);

    for (int i = 0; i < size; ++i)
        minimum = min<T>(minimum, tab[i]);

    for (int i = 1; i < size; ++i)
        if (tab[i] == minimum)
            return (tab[i]);
    return (minimum);
}

int &nonTemplateMin(int *tab, int size)
{
    int minimum = tab[0];

    for (int i = 1; i < size; ++i)
        minimum = min(minimum, tab[i]);


    for (int i = 0; i < size; ++i)
        if (tab[i] == minimum)
            return (tab[i]);
    return (minimum);
}

#endif /* !EX02_HPP_ */