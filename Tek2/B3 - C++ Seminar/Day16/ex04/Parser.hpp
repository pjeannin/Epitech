/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <sstream>
#include <stack>

class Parser {
    public:
        Parser();
        Parser(const Parser &other);
        ~Parser();
        Parser &operator=(const Parser &other);
        void feed(const std::string &expr);
        int result() const;
        void reset();

    protected:
    private:
        void compute(int firstNumber, int secondNumber);
        std::stack<int> _numbers;
        std::stack<char> _tmpStack;
        int _res;
};

#endif /* !PARSER_HPP_ */
