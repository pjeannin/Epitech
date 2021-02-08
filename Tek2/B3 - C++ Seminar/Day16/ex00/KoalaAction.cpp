/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** KoalaAction
*/

#include "KoalaAction.hpp"

KoalaAction::KoalaAction()
{
}

KoalaAction::~KoalaAction()
{
}

void KoalaAction::eat(const std::string &sentence)
{
    std::cout << "I eat: " << sentence << std::endl;
}

void KoalaAction::sleep(const std::string &snetence)
{
    std::cout << "I sleep, and drema of: " << snetence << std::endl;
}

void KoalaAction::goTo(const std::string &sentence)
{
    std::cout << "I go to: " << sentence << std::endl;
}

void KoalaAction::reproduce(const std::string &sentence)
{
    std::cout << "I attempt to reproduce with: " << sentence << std::endl;
}