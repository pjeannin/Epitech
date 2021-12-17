/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** LittleHand
*/

#include <iostream>
#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}


void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    Fruit *currentFruit = nullptr;
    bool boxIsFull = false;
    int max = unsorted.nbFruits();

    while (max--) {
        currentFruit = unsorted.pickFruit();
        boxIsFull = true;
        if (currentFruit->getName() == "lemon") {
            if (lemons.putFruit(currentFruit) == true)
                boxIsFull = false;
        } else if (currentFruit->getName() == "banana") {
            if (bananas.putFruit(currentFruit) == true)
                boxIsFull = false;
        } else if (currentFruit->getName() == "lime") {
            if (limes.putFruit(currentFruit) == true)
                boxIsFull = false;
        }
        if (boxIsFull == true)
            unsorted.putFruit(currentFruit);
    }
}