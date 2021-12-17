/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** Infos
*/

#include "Infos.hpp"

Infos::Infos()
{
}

Infos::~Infos()
{
}


UserModule &Infos::getUserModule() { return (_user); }

OSModule &Infos::getOSModule() { return (_os); }

TimeModule &Infos::getTimeModule() { return (_time); }

RamModule &Infos::getRamModule() { return (_ram); }

CpuModule &Infos::getCpuModule() { return (_cpu); }