/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin [WSL: Ubuntu]
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <filesystem>
#include <iostream>
#include <exception>

class Error: public std::exception
{
    public:
        Error(std::string str) {_str = str;};
        Error() {_str = "An error happend";};

        virtual const char* what() const throw()
        {
                return _str.c_str();
        }

    private:
        std::string _str;
};

#endif /* !ERROR_HPP_ */
