/*
** EPITECH PROJECT, 2021
** B4 - Concurrent Programming
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : public std::exception {
    public:
        Exception(const std::string &message) : _message(message) {};
        virtual ~Exception() throw() {};
        virtual const char *what() const throw() { return _message.c_str(); }

    protected:
    private:
        std::string _message;
};

#endif /* !EXCEPTION_HPP_ */
