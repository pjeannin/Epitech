/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** main
*/

#include <string>
#include <fstream>
#include <iostream>
#include "include/Handler.hpp"
#include "include/Parser.hpp"

int main(int argc, char **argv)
{
    std::string filename;
    std::string extention;

    if (argc != 2) {
        std::cerr << "Nanotekspice takes one and only one circuit file as parameters." << std::endl << std::endl << "USAGE:" << std::endl << "\t./nanotekspice CircuitFile.nts" << std::endl;
        return (84);
    } else {
        filename = argv[1];
        extention = &argv[1][filename.length() - 4];
        if (extention != ".nts") {
            std::cerr << "Nanotekspice only takes circuit file as parameters." << std::endl << std::endl << "USAGE:" << std::endl << "\t./nanotekspice CircuitFile.nts" << std::endl;
            return (84);
        }
        std::ifstream fileStream(filename, std::ios::in);
        std::ifstream fileStream2(filename, std::ios::in);
        if (!fileStream) {
            std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
            return (84);
        }
        if (!nts::Parser::parserErrors(fileStream2)) {
            std::cerr << "wrong input" << std::endl;
            return (84);
        }
        try {
            nts::Handler::run(fileStream);
        } catch (Error e) {
            std::cerr << "Where {" << e.where() << "} What {" << e.what() << "}" << std::endl;
            return (84);
        } catch (std::exception e) {
            std::cerr << "What {" << e.what() << "}" << std::endl;
            return (84);
        }
    }
    return (0);
}