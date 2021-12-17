/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}


void ToyStory::tellMeAStory(const std::string &fileName, Toy toy1, bool(Toy::*func1)(const std::string), Toy toy2, bool(Toy::*func2)(const std::string))
{
    std::ifstream file(fileName, std::ios::in);
    std::string line;
    Toy toyTab[2] = { toy1, toy2 };
    bool (Toy::*funcTab[2])(const std::string str) = { func1 , func2 };
    int index = 0;

    if (!file.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    for (int i = 0; i < 2; ++i) {
        auto error = toyTab[i].getLastError();
        if (error.type != Toy::Error::UNKNOWN) {
            std::cout << error.where() << ": " << error.what() << std::endl;
            file.close();
            return;
        }
    }
    std::cout << toy1.getAscii() << std::endl << toy2.getAscii() << std::endl;
    while (getline(file, line)) {
        if (line.find("picture:") == 0) {
            line.erase(0, 8);
            toyTab[index].setAscii(line);
            auto error = toyTab[index].getLastError();
            if (error.type != Toy::Error::UNKNOWN) {
                std::cout << error.where() << ": " << error.what() << std::endl;
                file.close();
                return;
            }
            std::cout << toyTab[index].getAscii();
        } else {
            (toyTab[index].*(funcTab[index]))(line);
            auto error = toyTab[index].getLastError();
            if (error.type != Toy::Error::UNKNOWN) {
                std::cout << error.where() << ": " << error.what() << std::endl;
                file.close();
                return;
            }
            index = (++index) % 2;
        }
    }
}