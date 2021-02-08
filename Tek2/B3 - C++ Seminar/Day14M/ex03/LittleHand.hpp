/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "Coconut.hpp"
#include "FruitBox.hpp"
#include "MixerBase.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
        static FruitBox *const *organizeCoconut(Coconut const *const *coconuts);
        static void plugMixer(MixerBase &mixer);

    protected:
    private:
};

#endif /* !LITTLEHAND_HPP_ */
