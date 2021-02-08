/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public:
        FruitNode(Fruit *content);
        ~FruitNode();
        FruitNode *next;
        Fruit *_content;

    protected:
    private:
};

#endif /* !FRUITNODE_HPP_ */
