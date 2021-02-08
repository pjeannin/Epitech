/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** LittleHand
*/

#include <iostream>
#include "LittleHand.hpp"
#include "Mixer.hpp"

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

FruitBox *const *LittleHand::organizeCoconut(Coconut const *const *coconuts)
{
    int nbBox = 0;
    int index = 0;

    for (int i = 0; coconuts[i]; ++i)
        ++nbBox;
    nbBox = (nbBox / 6) + ((nbBox / 6) * 6 < nbBox ? 1 : 0);
    FruitBox **boxTab = new FruitBox*[nbBox + 1];
    for (int i = 0; i <= nbBox; ++i)
        boxTab[i] = nullptr;
    if (nbBox == 0)
        return (boxTab);
    boxTab[0] = new FruitBox(6);
    for (int i = 0; coconuts[i]; ++i) {
        if (i != 0 && i % 6 == 0)
            boxTab[++index] = new FruitBox(6);
        boxTab[index]->putFruit(const_cast<Coconut *>(coconuts[i]));
    }
    boxTab[++index] = nullptr;

    return (boxTab);
}

void LittleHand::plugMixer(MixerBase &mixer)
{
    Mixer newMixer;
    newMixer.plug();
    mixer = newMixer;
}
