/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** UserModule
*/

#include <ncurses.h>
#include "UserModule.hpp"
#include "SFML/GraphicalWindow.hpp"

UserModule::UserModule()
{
    char tmp[255];

    gethostname(tmp, 255);
    _hostName = strdup(tmp);
    getlogin_r(tmp, 255);
    _userName = strdup(tmp);
    _key = 'u';
    _isActiv = true;
}

void UserModule::displayNcurses()
{
	attron(COLOR_PAIR(1));
    printw("\tHostname: ");
	attron(COLOR_PAIR(2));
    printw("%s\t\t", _hostName.c_str());
	attron(COLOR_PAIR(1));
    printw("\tUsername: ");
	attron(COLOR_PAIR(2));
    printw("%s\t\n\n", _userName.c_str());
}

void UserModule::displaySFML(sf::RenderWindow *window)
{
    displayTitle(window, "Hostname :", 200, 60, 25);
    displayText(window, _hostName, 415, 60, 25);
    displayTitle(window, "Username :", 680, 60, 25);
    displayText(window, _userName, 890, 60, 25);
}

// displayTitle(window, "Hostname :", 200, 60, 25);
// displayText(window, "pc-29.home", 415, 60, 25);
// displayTitle(window, "Username :", 680, 60, 25);
// displayText(window, "trominger", 890, 60, 25);

void UserModule::setStatus()
{
    if (_isActiv == true)
        _isActiv = false;
    else
        _isActiv = true;
}

const std::string &UserModule::getHostName() const { return (_hostName); }

const std::string &UserModule::getUserName() const { return (_userName); }

bool UserModule::getStatus() const { return (_isActiv); }

char UserModule::getKey() const { return (_key); }
