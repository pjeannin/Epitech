/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** Container
*/

#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

#include <iostream>
#include <algorithm>

template<typename T>
void add(T &t) { ++t; }

template <typename T>
void aff(T &t) { std::cout << "Value: " << t << std::endl; }

template<typename T, template<typename, typename> class container>
class contain {
    public:
        void push(T value) { _myContainer.push_back(value); }
        void aff() { std::for_each(_myContainer.begin(), _myContainer.end(), &::aff<T>); }
        void add() { std::for_each(_myContainer.begin(), _myContainer.end(), &::add<T>); }

    protected:
    private:
        container<T, std::allocator<T> > _myContainer;
};

#endif /* !CONTAINER_HPP_ */
