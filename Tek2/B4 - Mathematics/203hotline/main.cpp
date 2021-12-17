/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203hotline-pierre.jeannin
** File description:
** main
*/

#include <iostream>
#include <string>
#include <exception>
#include "Hotline.hpp"

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

int errorHandling(int argc, char **argv, int &mode, Hotline &hotline)
{
    if (argc == 2) {
        if ((*new std::string (argv[1]) == "-h")) {
            std::cout << "USAGE" << std::endl << "    ./hotline [n k | d]" <<
            std::endl << std::endl << "DESCRIPTION" << std::endl << "    n       n value for the computation of C(n, k)" <<
            std::endl << "    k       k value for the computation of C(n, k)" << std::endl <<
            "    d       average duration of calls (in seconds)" << std::endl;
            return (0);
        } else {
            try {
                if (!is_digits((argv[1])))
                    throw (std::exception());
                hotline.setCallDuration(atoi(argv[1]));
            } catch (std::exception e) {
                std::cout << "Oops, you must enter a positiv integer." << std::endl <<
                "./203hotline -h for more explainations.";
                return (-1);
            }
            if (hotline.getCallDuration() < 1) {
                std::cout << "Oops, you must enter a positiv integer." << std::endl <<
                "./203hotline -h for more explainations.";
                return (-1);
            }
            mode = 1;
        }
    } else if (argc == 3) {
        try {
            if (!is_digits((argv[1])) || !is_digits((argv[2])))
                    throw (std::exception());
            hotline.setN(atoi(argv[1]));
            hotline.setK(atoi(argv[2]));
        } catch (std::exception e) {
            std::cout << "Oops, you must enter two positiv integer." << std::endl <<
            "./203hotline -h for more explainations.";
            return (-1);
        }
        if (hotline.getN() < 1 || hotline.getK() < 0 || hotline.getN() < hotline.getK()) {
            std::cout << "Oops, you must enter two positiv integer." << std::endl <<
            "./203hotline -h for more explainations.";
            return (-1);
        }
        mode = 2;
    } else {
        std::cout << "Please use ./203hotline -h to know how to use it." << std::endl;
        return (-1);
    }

    return (0);
}

int main(int argc, char **argv)
{
    int mode = -1;
    Hotline hotline;

    if (errorHandling(argc, argv, mode, hotline) == -1)
        return (84);
    if (mode == 2) {
        std::cout << hotline.getK() << "-combinations of a set of size " << hotline.getN() << ":" << std::endl <<
        std::fixed << std::setprecision(0) << hotline.computeBinomialCoef() << std::endl;
    } else {
        std::cout << "Binomial distribution:" << std::endl;
        hotline.binomialLaw();
        std::cout << std::endl << "Poisson distribution:" << std::endl;
        hotline.poissonLaw();
    }

    return (0);
}