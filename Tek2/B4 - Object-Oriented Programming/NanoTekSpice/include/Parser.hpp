/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <fstream>
#include <string>
#include "Circuit.hpp"

namespace nts {
    class Parser {
        public:
            static void parse(std::ifstream &fileStream, Circuit &circuit);
            static bool parserErrors(std::ifstream &fileStream);

        protected:
        private:
            static std::string &cleanLine(std::string &line, char sep);
            static bool wordInFile(std::ifstream &fileStream, std::string word);
            static bool doesExist(Circuit &circuit, std::string toTest);
            static bool isbegeningOfLine(std::string base, std::string toFind);
    };
}

#endif /* !PARSER_HPP_ */
