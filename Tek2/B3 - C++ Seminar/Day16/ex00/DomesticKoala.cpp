/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action) : _actions(action)
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &koala)
{
    _actions = koala._actions;
    _fonctions = *new std::vector<methodPointer_t>(koala._fonctions);
    _commands = *new std::vector<unsigned char>(koala._commands);
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &koala)
{
    _actions = koala._actions;
    _fonctions = *new std::vector<methodPointer_t>(koala._fonctions);
    _commands = *new std::vector<unsigned char>(koala._commands);

    return (*this);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    if (std::find(_commands.begin(), _commands.end(), command) != _commands.end()
    || std::find(_fonctions.begin(), _fonctions.end(), action) != _fonctions.end())
        return;
    _fonctions.push_back(action);
    _commands.push_back(command);
}

const std::vector<methodPointer_t> *DomesticKoala::getActions() const { return (&_fonctions); }

void DomesticKoala::unlearnAction(unsigned char command)
{
    if (std::find(_commands.begin(), _commands.end(), command) == _commands.end())
        return;
    int index = 0;
    for (; _commands[index] != command; ++index);
    _commands.erase(_commands.begin() + index);
    _fonctions.erase(_fonctions.begin() + index);
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    if (std::find(_commands.begin(), _commands.end(), command) == _commands.end())
        return;
    int index = 0;
    for (; _commands[index] != command; ++index);
    (_actions.*_fonctions[index])(param);
}

void DomesticKoala::setKoalaAction(KoalaAction &koala) { _actions = koala; }