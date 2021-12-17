/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** TimeModule
*/

#include <ncurses.h>
#include "TimeModule.hpp"

TimeModule::TimeModule()
{
    time_t now = time(0);
    _currentTime = strdup(ctime(&now));
    _key = 't';
    _isActiv = true;
}

TimeModule::~TimeModule()
{
}

void TimeModule::displayNcurses()
{
    updateCurrentTime();
	attron(COLOR_PAIR(1));
    printw("\tDate & Time: ");
	attron(COLOR_PAIR(2));
    printw("%s\t\n", _currentTime.c_str());
}

void TimeModule::displaySFML(sf::RenderWindow *window)
{
    updateCurrentTime();
    displayTitle(window, "Date :", 590, 150, 20);
    displayText(window, _currentTime.c_str(), 680, 150, 20);
}

// displayTitle(window, "Date :", 590, 150, 20);
// displayText(window, "Sat Jan 23 17:30:49 2021", 680, 150, 20);

const std::string &TimeModule::getCurrentTime() const { return (_currentTime); }

void TimeModule::updateCurrentTime()
{
    time_t now = time(0);

    _currentTime = strdup(ctime(&now));
}

void TimeModule::setStatus()
{
    if (_isActiv == true)
        _isActiv = false;
    else
        _isActiv = true;
}

bool TimeModule::getStatus() const { return (_isActiv); }

char TimeModule::getKey() const { return (_key); }
