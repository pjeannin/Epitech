/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Minishell
*/

#ifndef MINISHELL_HPP_
#define MINISHELL_HPP_

#include <string>
#include <algorithm>
#include "Circuit.hpp"

namespace nts {
    class Minishell {
        public:
            Minishell(Circuit &circuit);
            ~Minishell();
            void run();

        protected:
        private:
            void loop();
            void simulate();
            void setInput(std::string command);
            void display();
            std::string getCommand(std::string commandLine, char sep);
            bool checkIfCommdnExist(std::string commandLine);
            bool charIsPresent(std::string commandLine, char toFind);
            void sortList (std::vector<IComponent *> address_book);
            Circuit _circuit;
            int _tick;
            const static char prompt = '>';
    };
}

#endif /* !MINISHELL_HPP_ */
