/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class IMonitorModule {
    public:
        virtual bool getStatus() const = 0;
        virtual char getKey() const = 0;
        virtual void setStatus() = 0;
        virtual void displayNcurses() = 0;
        virtual void displaySFML(sf::RenderWindow *window) = 0;

    protected:
    private:
};

#endif /* !IMONITORMODULE_HPP_ */
