/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD15-pierre.jeannin
** File description:
** ex00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    if (a < b)
        return (a);
    else if (b < a)
        return (b);

    return (b);
}

template <typename T>
const T &max(const T &a, const T &b)
{
    if (a > b)
        return (a);
    else if (b > a)
        return (b);

    return (b);
}

template <typename T>
const T add(const T a, const T b)
{
    return (a + b);
}


#endif /* !EX00_HPP_ */

