/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>

class Error : public std::exception {
    public:
        Error(const std::string &where = "Nanotekspice don't know where the error occured.", const std::string &what = "Nanotekspice don't know what the error is.") throw();
        ~Error() throw();
        const std::string &where() throw();
        const char *what() throw();

    protected:
        std::string _what;
        std::string _where;
    private:
};

#endif /* !ERROR_HPP_ */
