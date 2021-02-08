/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush2-auguste.thomann
** File description:
** wrap
*/

#include "../class/Box.hpp"
#include "../class/GiftPaper.hpp"
#include "../class/LittlePony.hpp"
#include "../class/Teddy.hpp"

Object *MyUnitTests(Object **tab)
{
    Toy *t = dynamic_cast<Toy *>(tab[0]);
    Box *b = dynamic_cast<Box *>(tab[1]);
    GiftPaper *gp = dynamic_cast<GiftPaper *>(tab[2]);
    if (t == nullptr) {
        std::cout << "The first elelent is not a Toy" << std::endl;
        return (nullptr);
    } else if (b == nullptr) {
        std::cout << "The second element is not a Box" << std::endl;
        return (nullptr);
    } else if (gp == nullptr) {
        std::cout << "The third element is not a Gift Paper" << std::endl;
        return (nullptr);
    }
    std::cout << "Expected:" << std::endl << "A box can only wrap a toy" << std::endl << "The toy has to be taken to be wraped" << std::endl << "Impossible to wrap an empty box" << std::endl;
    std::cout << "gra hu" << std::endl << "tuuuut tuuut tuut" << std::endl << "tuuuut tuuut tuut" << std::endl << "Got:" << std::endl;
    b->openMe();
    b->wrapMeThat(gp);
    b->closeMe();
    b->wrapMeThat(tab[0]);
    gp->wrapMeThat(b);
    b->openMe();
    t->isTaken();
    b->wrapMeThat(tab[0]);
    b->closeMe();
    gp->wrapMeThat(b);

    return (gp);
}

void wrap(void)
{
    Object *tab[3];
    tab[0] =  new Teddy("hhaa");
    tab[1] = new Box();
    tab[2] = new GiftPaper();

    MyUnitTests(tab);
}