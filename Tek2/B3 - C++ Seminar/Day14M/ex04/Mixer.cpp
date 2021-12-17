/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** Mixer
*/

#include "Mixer.hpp"

int mixer(FruitBox &fruits)
{
    int vitaminsTotal = 0;
    const Fruit *tmp;

    while ((tmp = fruits.pickFruit()) != nullptr)
        vitaminsTotal += tmp->getVitamins();

    return (vitaminsTotal);
}

Mixer::Mixer() : MixerBase()
{
    _plugged = false;
    _mixfunc = &mixer;
}

Mixer::~Mixer()
{
}

int Mixer::mix(FruitBox &fruits) const
{
    if (_plugged)
        return (_mixfunc(fruits));

    return (0);
}

void Mixer::plug() { _plugged = true; }