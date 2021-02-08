/*
** EPITECH PROJECT, 2021
** Display.cpp
** File description:
** 
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "GraphicalWindow.hpp"


GraphicalWindow::GraphicalWindow() : IMonitorDisplay()
{
    GraphicalWindow::_modules.push_back(new UserModule);
    GraphicalWindow::_modules.push_back(new TimeModule);
    GraphicalWindow::_modules.push_back(new OSModule);
    GraphicalWindow::_modules.push_back(new RamModule);
    GraphicalWindow::_modules.push_back(new CpuModule);
    GraphicalWindow::_modules.push_back(new NetworkModule);
}
    
GraphicalWindow::~GraphicalWindow()
{

}

void GraphicalWindow::changeModuleStatus(sf::RenderWindow &window,
    sf::Event &event)
{
    IMonitorModule *tmp = _modules[0];
    char key;

    switch (event.key.code) {
        case (sf::Keyboard::Q):
            window.close();
            break;
        case (sf::Keyboard::U):
            key = 'u';
            break;
        case (sf::Keyboard::R):
            key = 'r';
            break;
        case (sf::Keyboard::T):
            key = 't';
            break;
        case (sf::Keyboard::C):
            key = 'c';
            break;
        case (sf::Keyboard::O):
            key = 'o';
            break;
        case (sf::Keyboard::N):
            key = 'n';
            break;
        default:
            break;
    }
    for (auto i = _modules.begin(); i != _modules.end(); i++) {
        tmp = *i;
        if (tmp->getKey() == key || tmp->getKey() == (key - 32)) {
            tmp->setStatus();
            break;
        }
    }
}

void GraphicalWindow::displayModules()
{
    IMonitorModule *tmp = _modules[0];
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Rush3");
    sf::Texture texture;

    if (texture.loadFromFile("SFML/interface.png") != true)
        return;
    sf::Sprite sprite(texture);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
                changeModuleStatus(window, event);
        window.clear(sf::Color::Black);
        window.draw(sprite);
        for (auto i = _modules.begin(); i != _modules.end(); i++) {
            tmp = *i;
            if (tmp->getStatus() == true)
                tmp->displaySFML(&window);
        }
        window.display();
    }
}

void GraphicalWindow::changeModuleStatus(char key)
{
    IMonitorModule *tmp = _modules[0];

    for (auto i = _modules.begin(); i != _modules.end(); i++) {
        tmp = *i;
        if (tmp->getKey() == key) {
            tmp->setStatus();
            break;
        }
    }
}

char GraphicalWindow::checkKeyPressed(char c)
{
    if (c == 'q')
        return (c);
    else
        changeModuleStatus(c);
    return ('z');
}
