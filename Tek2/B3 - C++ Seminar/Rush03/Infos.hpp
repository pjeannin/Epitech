/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** Infos
*/

#ifndef INFOS_HPP_
#define INFOS_HPP_

#include "UserModule.hpp"
#include "OSModule.hpp"
#include "TimeModule.hpp"
#include "RamModule.hpp"
#include "CpuModule.hpp"

class Infos {
    public:
        Infos();
        ~Infos();

        UserModule &getUserModule();
        OSModule &getOSModule();
        TimeModule &getTimeModule();
        RamModule &getRamModule();
        CpuModule &getCpuModule();

    protected:
    private:
        UserModule _user;
        OSModule _os;
        TimeModule _time;
        RamModule _ram;
        CpuModule _cpu;
};

#endif /* !INFOS_HPP_ */
