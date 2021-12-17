/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** TimeModule
*/

#ifndef TIMEMODULE_HPP_
#define TIMEMODULE_HPP_

#include <ctime>
#include <string.h>
#include <string>
#include "IMonitorModule.hpp"
#include "SFML/Affichage/print.hpp"

class TimeModule : public IMonitorModule {
    public:
        TimeModule();
        ~TimeModule();
        const std::string &getCurrentTime() const;
        void updateCurrentTime();
        bool getStatus() const;
        char getKey() const;
        void setStatus();
        void displayNcurses();
        void displaySFML(sf::RenderWindow *window);

    protected:
    private:
        std::string _currentTime;
        char _key;
        bool _isActiv;
};

#endif /* !TIMEMODULE_HPP_ */
