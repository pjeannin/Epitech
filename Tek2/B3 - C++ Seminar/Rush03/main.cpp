/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** test
*/

#include <cstring>
#include <iostream>
#include "ncursesDisplay.hpp"
#include "SFML/GraphicalWindow.hpp"

int main(int ac, char **av)
{
    if (ac > 1) {
        if (strcmp(av[1], "text") == 0) {
            ncursesDisplay ncurs;
            ncurs.displayModules();
        } else if (strcmp(av[1], "graphical") == 0) {
            GraphicalWindow graphical;
            graphical.displayModules();
        } else {
            std::cerr << "USAGE : ./MyGKrellm [text / graphical]" << std::endl;
            return (84);
        }
    } else {
        std::cerr << "USAGE : ./MyGKrellm [text / graphical]" << std::endl;
        return (84);
    }
}
