/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        FruitBox(const FruitBox &fruitBox) = delete;
        FruitBox &operator=(const FruitBox &fruitBox) = delete;
        ~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit *fruit);
        Fruit *pickFruit();
        FruitNode *head() const;

    protected:
    private:
        int _size;
        int _nbInside;
        FruitNode *_headNode;
};

#endif /* !FRUITBOX_HPP_ */
