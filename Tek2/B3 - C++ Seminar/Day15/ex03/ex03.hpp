/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD15-pierre.jeannin
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void foreach(const T *tab, void (func)(const T &), int size)
{
    for (int i = 0; i < size; ++i)
        (func)(tab[i]);
}

template<typename T>
void print(const T &elem) { std::cout << elem << std::endl; }

#endif /* !EX03_HPP_ */