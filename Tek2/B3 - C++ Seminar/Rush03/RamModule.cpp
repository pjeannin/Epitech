/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** RamModule
*/

#include <iomanip>
#include <ncurses.h>
#include "RamModule.hpp"

RamModule::RamModule()
{
    struct sysinfo memInfo;

    sysinfo(&memInfo);
    _totalRam = memInfo.totalram * memInfo.mem_unit;
    _freeRam = memInfo.freeram * memInfo.mem_unit;
    _usedRam = _totalRam - _freeRam;
    _key = 'r';
    _isActiv = true;
}

RamModule::~RamModule()
{
}

void RamModule::displayNcurses()
{
    updateRam();
	attron(COLOR_PAIR(1));
    printw("\tRAM: ");
    int percRam = _usedRam * 100 / _totalRam;
    attron(COLOR_PAIR(5));
    if (percRam > 80)
        attron(COLOR_PAIR(3));
    else if (percRam < 50)
        attron(COLOR_PAIR(4));
    printw("%.2fGB / %.2fGB (%d%%) - %.2fGB free\t\n",
        ((float)_usedRam / 1073741824), ((float)_totalRam / 1073741824),
        percRam, (float)_freeRam / 1073741824);
    attron(COLOR_PAIR(1));
    printw("\t|");
    attron(COLOR_PAIR(8));
    if (percRam > 80)
        attron(COLOR_PAIR(6));
    else if (percRam < 50)
        attron(COLOR_PAIR(7));
    for (int i = 0;  i < percRam / 5; i++) {
        printw(" ");
    }
    attron(COLOR_PAIR(1));
    for (int i = 0; i < (20 - percRam / 5); i++) {
        printw("-");
    }
    attron(COLOR_PAIR(1));
    printw("|\n\n");
}

void RamModule::displaySFML(sf::RenderWindow *window)
{
    updateRam();
    std::ostringstream tmp;
    int pourc = _usedRam * 100 / _totalRam;
    int size;
    tmp << std::setprecision(3) << ((float)_usedRam / 1073741824)
        << " GB / " << std::setprecision(3) << ((float)_totalRam / 1073741824)
        << " GB (" << pourc << "%) - " << ((float)_freeRam / 1073741824)
        << " GB free";
    size = pourc * 400 / 100;
    std::string str(tmp.str());
    displayShape(window, 320, 600, 600, 250);
    displayTitle(window, "RAM Module :", 350, 550, 25);
    displayText(window, str, 340, 610, 22);
    displayShape(window, 420, 700, 400, 50);
    displayBar(window, 426, 706, size, 38);
}

void RamModule::updateRam()
{
    struct sysinfo memInfo;

    sysinfo(&memInfo);
    _freeRam = memInfo.freeram * memInfo.mem_unit;
    _usedRam = _totalRam - _freeRam;
}

void RamModule::setStatus()
{
    if (_isActiv == true)
        _isActiv = false;
    else
        _isActiv = true;
}


long long RamModule::getTotalRam()const { return (_totalRam); }

long long RamModule::getFreeRam()const { return (_freeRam); }

long long RamModule::getUsedRam()const { return (_usedRam); }

bool RamModule::getStatus() const { return (_isActiv); }

char RamModule::getKey() const { return (_key); }