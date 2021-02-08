/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush2-auguste.thomann
** File description:
** unitTest
*/

#include <iostream>
#include "unitTest.hpp"

int main(void)
{
    std::cout << "Start test" << std::endl << std::endl << "Toy :" << std::endl << std::endl;
    toy();
    std::cout << std::endl << "Wrap :" << std::endl << std::endl;
    wrap();
    std::cout << std::endl << "ConveyorBelt :" << std::endl << std::endl;
    conveyorBelt();
    std::cout << std::endl << "Elf :" << std::endl << std::endl;
    elf();
}