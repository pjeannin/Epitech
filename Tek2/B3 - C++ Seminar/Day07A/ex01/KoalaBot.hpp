/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
        void setParts(const Arms &arm);
        void setParts(const Legs &leg);
        void setParts(const Head &head);
        void swapParts(Arms &arm);
        void swapParts(Legs &leg);
        void swapParts(Head &head);
        void informations() const;
        bool status() const;

    protected:
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string  _serial;
};

#endif /* !KOALABOT_HPP_ */
