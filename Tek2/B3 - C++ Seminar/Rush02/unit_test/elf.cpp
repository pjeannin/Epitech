/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush2-auguste.thomann
** File description:
** elf
*/

#include "../class/Box.hpp"
#include "../class/GiftPaper.hpp"
#include "../class/LittlePony.hpp"
#include "../class/Teddy.hpp"
#include "../class/PapaXmasElf.hpp"

void MyUnitTest(PapaXmasElf *elf, Teddy *teddy)
{
    std::cout << "Expected:" <<std::endl << "Elves can only wrap toys !" << std::endl << "Elves can only wrap toys !" << std::endl << "gra hu" << std::endl;
    std::cout << "tuuuut tuuut tuut" << std::endl << "tuuuut tuuut tuut" <<std::endl << "Got:" << std::endl;
    elf->wrap(nullptr);
    elf->wrap(new Box());
    elf->wrap(teddy);
}

void elf(void)
{
    PapaXmasElf *elf = new PapaXmasElf("Jean-Luc");
    Teddy *teddy = new Teddy("Hugues");

    MyUnitTest(elf, teddy);
}