/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** DomesticKoala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "KoalaAction.hpp"

using methodPointer_t = void(KoalaAction::*)(const std::string &);

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &);
        DomesticKoala(const DomesticKoala &);
        ~DomesticKoala();
        DomesticKoala &operator=(const DomesticKoala &);
        const std::vector<methodPointer_t> *getActions() const;
        void learnAction(unsigned char command , methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);

    protected:
    private:
        KoalaAction _actions;
        std::vector<methodPointer_t> _fonctions;
        std::vector<unsigned char> _commands;
};

#endif /* !DOMESTICKOALA_HPP_ */
