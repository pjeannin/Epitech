/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** OSModule
*/

#include <ncurses.h>
#include "OSModule.hpp"

OSModule::OSModule()
{
    struct utsname uts;

    uname(&uts);
    _osName = strdup(uts.sysname);
    _kernelVersion = strdup(uts.release);
    _key = 'o';
    _isActiv = true;
}

OSModule::~OSModule()
{
}

void OSModule::displayNcurses()
{
	attron(COLOR_PAIR(1));
    printw("\tOperating System: ");
	attron(COLOR_PAIR(2));
    printw("%s\t", _osName.c_str());
	attron(COLOR_PAIR(1));
    printw("\tKernel Version: ");
	attron(COLOR_PAIR(2));
    printw("%s\n\n", _kernelVersion.c_str());
}

void OSModule::displaySFML(sf::RenderWindow *window)
{
    displayTitle(window, "Operating System :", 250, 920, 25);
    displayText(window, _osName, 610, 920, 25);
    displayTitle(window, "Kernel Version :", 250, 955, 16);
    displayText(window, _kernelVersion, 445, 955, 16);
}

// displayTitle(window, "Operating System :", 250, 920, 25);
// displayText(window, "Linux", 610, 920, 25);
// displayTitle(window, "Kernel Version :", 250, 955, 16);
// displayText(window, "5.3.16-200.fc30.x86_64", 445, 955, 16);

void OSModule::setStatus()
{
    if (_isActiv == true)
        _isActiv = false;
    else
        _isActiv = true;
}

const std::string &OSModule::getOsName() const { return (_osName); }

const std::string &OSModule::getKernelVesion() const { return (_kernelVersion); }

bool OSModule::getStatus() const { return (_isActiv); }

char OSModule::getKey() const { return (_key); }
