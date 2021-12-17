/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Babel
*/


#ifndef __BABEL_PRINT_HPP__
#define __BABEL_PRINT_HPP__

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define OK_MSG "[" << GREEN << "OK"  << RESET << "] "
#define OK_PRINT(str) std::cout << OK_MSG << str << std::endl

#define ERROR_MSG "[" << RED << "ERROR"  << RESET << "] "
#define ERROR_PRINT(str) std::cout << ERROR_MSG << str << std::endl

#define DEBUG_MSG "[" << CYAN << "Debug"  << RESET << "] "
#ifdef DEBUG
    #define DEBUG_PRINT(str) std::cout << DEBUG_MSG << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << " -> " << str << std::endl
#else
    #define DEBUG_PRINT(str)
#endif

#endif //__BABEL_PRINT_HPP__
