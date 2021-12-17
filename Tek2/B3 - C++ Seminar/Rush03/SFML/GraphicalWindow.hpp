/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** GraphicalWindow
*/

#ifndef GRAPHICALWINDOW_HPP_
#define GRAPHICALWINDOW_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "../IMonitorDisplay.hpp"
#include "../IMonitorModule.hpp"
#include "../CpuModule.hpp"
#include "../RamModule.hpp"
#include "../NetworkModule.hpp"
#include "../OSModule.hpp"
#include "../TimeModule.hpp"
#include "../UserModule.hpp"


class GraphicalWindow : public IMonitorDisplay {
    public :
        GraphicalWindow();
        ~GraphicalWindow();

        void displayModules();
        char checkKeyPressed(char c);
        void changeModuleStatus(char key);
        void changeModuleStatus(sf::RenderWindow &window, sf::Event &event);

    private :
        std::vector<IMonitorModule *> _modules;
};


#endif /* !GRAPHICALWINDOW_HPP_ */
