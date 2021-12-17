/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "Core.hpp"

int main (int argc, char **argv)
{
    Core core;
    if (argc != 2) {
        std::cerr << "Not enough arguments\nUSAGE: ./arcade libPath" << std::endl;
        return (84);
    }
    try {
        core.run(argv[1]);
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return (0);
}