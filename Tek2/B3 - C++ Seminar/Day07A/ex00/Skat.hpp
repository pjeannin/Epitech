/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>

class Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks();
        int &stimPaks(int stimpack);
        const std::string &name();

        void shareStimPaks(int number , int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
    private:
        std::string _name;
        int _stimpaks;
};

#endif /* !SKAT_HPP_ */
