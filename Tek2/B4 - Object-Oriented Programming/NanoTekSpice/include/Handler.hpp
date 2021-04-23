/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Nanotekspice
*/

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

#include <fstream>
#include "Error.hpp"
#include "Parser.hpp"
#include "Minishell.hpp"

namespace nts {
    class Handler {
        public:
            static void run(std::ifstream &fileStream);

        protected:
        private:
    };
}

#endif /* !NANOTEKSPICE_HPP_ */
