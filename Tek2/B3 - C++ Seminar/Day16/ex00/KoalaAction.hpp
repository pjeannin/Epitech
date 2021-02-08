/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** KoalaAction
*/

#ifndef KOALAACTION_HPP_
#define KOALAACTION_HPP_

#include <string>
#include <iostream>

class KoalaAction {
    public:
        KoalaAction();
        ~KoalaAction();
        void eat(const std::string &sentence);
        void sleep(const std::string &sentence);
        void goTo(const std::string &sentence);
        void reproduce(const std::string &sentence);

    protected:
    private:
};

#endif /* !KOALAACTION_HPP_ */
