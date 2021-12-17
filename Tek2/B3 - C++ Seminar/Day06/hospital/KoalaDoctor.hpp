/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <string>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        void diagnose(SickKoala *koala);
        void timeCheck();
        std::string getName();

    protected:
    private:
        std::string _name;
        bool _is_working;
};

#endif /* !KOALADOCTOR_HPP_ */
