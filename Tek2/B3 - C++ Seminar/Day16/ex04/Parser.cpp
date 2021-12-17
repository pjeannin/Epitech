/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
    reset();
}

Parser::Parser(const Parser &other)
{
    _numbers = other._numbers;
    _tmpStack = other._tmpStack;
    _res = other._res;
}

Parser::~Parser()
{
}

Parser &Parser::operator=(const Parser &other)
{
    _numbers = other._numbers;
    _tmpStack = other._tmpStack;
    _res = other._res;

    return (*this);
}

void Parser::reset()
{
    std::stack<int> empty;
    std::stack<char> empty2;

    _tmpStack = empty2;
    _numbers = empty;
    _res = 0;
}

int Parser::result() const { return (_res); }

template<typename T>
T &poptop(std::stack<T> &stack)
{
    T tmp = stack.top();
    stack.pop();

    return (tmp);
}

void Parser::compute(int firstNumber, int secondNumber)
{
    switch (poptop(_tmpStack))
    {
        case '+' :
            _numbers.push(secondNumber + firstNumber);
            break;
        case '-' :
            _numbers.push(secondNumber - firstNumber);
            break;
        case '*' :
            _numbers.push(secondNumber * firstNumber);
            break;
        case '/' :
            _numbers.push(secondNumber / firstNumber);
            break;
        case '%' :
            _numbers.push(secondNumber % firstNumber);
            break;
        default:
            break;
    }
}

void Parser::feed(const std::string &expr)
{
    unsigned int i = 0;
    std::string stringNumber;
    int intNumber;

    while (i < expr.size()) {
        stringNumber.clear();
        if (expr[i] >= '0' && expr[i] <= '9') {
            while (expr[i] >= '0' && expr[i] <= '9')
                stringNumber += expr[i++];
            std::stringstream(stringNumber) >> intNumber;
            _numbers.push(intNumber);
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%' || expr[i] == '(') {
            _tmpStack.push(expr[i++]);
        } else if (expr[i] == ')') {
            i++;
            while (_tmpStack.top() != '(')
                compute(poptop(_numbers), poptop(_numbers));
            _tmpStack.pop();
        } else
            i++;
    }
    while (!_tmpStack.empty())
        compute(poptop(_numbers), poptop(_numbers));
    _res += _numbers.top();
    _numbers.pop();
}