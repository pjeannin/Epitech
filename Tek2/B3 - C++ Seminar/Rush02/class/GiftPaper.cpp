/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : Object("GiftPaper", "Wrap"), Wrap("GiftPaper")
{
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::closeMe() { return; }

void GiftPaper::wrapMeThat(Object *object)
{
    Box *box = dynamic_cast<Box *>(object);

    if (box == nullptr)
        std::cerr << "A box can only wrap a box" << std::endl;
    else if (box->isEmpty())
        std::cerr << "Impossible to wrap an empty box" << std::endl;
    else
        Wrap::wrapMeThat(object);
}