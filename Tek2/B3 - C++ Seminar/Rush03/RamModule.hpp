/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** RamModule
*/

#ifndef RAMMODULE_HPP_
#define RAMMODULE_HPP_

#include <string>
#include <string.h>
#include <sys/sysinfo.h>
#include "IMonitorModule.hpp"
#include "SFML/Affichage/print.hpp"

class RamModule : public IMonitorModule {
    public:
        RamModule();
        ~RamModule();
        long long getTotalRam() const;
        long long getFreeRam() const;
        long long getUsedRam() const;
        void updateRam();
        bool getStatus() const;
        char getKey() const;
        void setStatus();
        void displayNcurses();
        void displaySFML(sf::RenderWindow *window);

    protected:
    private:
        long long _totalRam;
        long long _freeRam;
        long long _usedRam;
        char _key;
        bool _isActiv;
};

#endif /* !RAMMODULE_HPP_ */
