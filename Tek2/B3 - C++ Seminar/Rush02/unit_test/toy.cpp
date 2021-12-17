/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "../class/Box.hpp"
#include "../class/GiftPaper.hpp"
#include "../class/LittlePony.hpp"
#include "../class/Teddy.hpp"

static bool testUnittest()
{
    Object *tab[2];

    tab[0] = new LittlePony("happy pony");
    tab[1] = new Teddy("cuddles");

    std::cout << "Expected:" << std::endl << "happy pony Toy yo man" << std::endl<< "cuddles Toy gra hu" << std::endl << "Got:" << std::endl;
    std::cout << tab[0]->getTitle() << " " << tab[0]->getType() << " ";
    dynamic_cast<Toy *>(tab[0])->isTaken();
    std::cout << tab[1]->getTitle(); std::cout << " " << tab[1]->getType() << " ";
    dynamic_cast<Toy *>(tab[1])->isTaken();
    if (tab[0]->getTitle() == "happy pony" && tab[0]->getType() == "Toy" && dynamic_cast<Toy *>(tab[0])->getToyStatus() == true
        && tab[1]->getTitle() == "cuddles" && tab[1]->getType() == "Toy" && dynamic_cast<Toy *>(tab[1])->getToyStatus() == true)
            return (true);

    return (false);
}

void toy(void)
{
    std::cout << (testUnittest() ? "Test passed" : "Test failed") << std::endl;
}