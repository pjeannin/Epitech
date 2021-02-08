/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include <string>
#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *koala);
        SickKoalaList();
        ~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *new_node);
        SickKoala *getFromName(std::string name);
        SickKoalaList *remove(SickKoalaList *to_remove);
        SickKoalaList *removeFromName(std::string to_remove);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();

    protected:
    private:
        SickKoala *_koala;
        SickKoalaList *_next;
};

#endif /* !SICKKOALALIST_HPP_ */
