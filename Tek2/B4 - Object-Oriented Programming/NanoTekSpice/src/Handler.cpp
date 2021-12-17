/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Nanotekspice
*/

#include "../include/Handler.hpp"

namespace nts {
    void Handler::run(std::ifstream &fileStream)
    {
        Circuit circuit;

        Parser::parse(fileStream, circuit);
        Minishell shell(circuit);
        shell.run();
    }
}