/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <string>

class SickKoala {
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string drug);
        void overDrive(std::string sentence);
        std::string getName();

    protected:
    private:
        std::string _name;
};

#endif /* !SICKKOALA_HPP_ */
