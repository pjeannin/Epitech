/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** Mixer
*/

#ifndef MIXER_HPP_
#define MIXER_HPP_

#include "MixerBase.hpp"

class Mixer : public MixerBase {
    public:
        Mixer();
        ~Mixer();
        void plug();
        int mix(FruitBox &fruits) const;

    protected:
    private:
};

#endif /* !MIXER_HPP_ */
