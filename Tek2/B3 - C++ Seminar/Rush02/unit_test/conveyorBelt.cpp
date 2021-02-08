/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush2-auguste.thomann
** File description:
** conveyorBelt
*/

#include "../class/Teddy.hpp"
#include "../class/PapaXmasConveyorBelt.hpp"

void MyUnitTest(PapaXmasConveyorBelt *belt)
{
    std::cout << "Expected:" << std::endl << "Can't use IN buttun with on object on the conveyer belt" << std::endl << "LUC" << std::endl << "Box" << std::endl << "GiftPaper" << std::endl << "Got:" << std::endl;
    belt->putObject(new Teddy("LUC"));
    belt->IN();
    std::cout << dynamic_cast<Teddy *>(belt->takeObject())->getTitle() << std::endl;
    belt->IN();
    std::cout << dynamic_cast<Box *>(belt->takeObject())->getTitle() << std::endl;
    belt->IN();
    std::cout << dynamic_cast<GiftPaper *>(belt->takeObject())->getTitle() << std::endl;
    belt->putObject(new Teddy("Nouveau LUC"));
    belt->OUT();
}

void conveyorBelt(void)
{
    PapaXmasConveyorBelt *belt = new PapaXmasConveyorBelt;

    MyUnitTest(belt);
}