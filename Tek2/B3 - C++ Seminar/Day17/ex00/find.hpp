/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** find
*/

#include <algorithm>

template<class Container>
class Container::iterator do_find(Container &container, int toFind) { return (std::find(container.begin(), container.end(), toFind)); }