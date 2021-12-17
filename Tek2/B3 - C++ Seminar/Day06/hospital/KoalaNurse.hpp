/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <string>
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *koala);
        std::string readReport(std::string filename);
        void timeCheck();
        int getID();

    protected:
    private:
        int _id;
        bool _is_working;
};

#endif /* !KOALANURSE_HPP_ */
