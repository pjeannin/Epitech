/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** print
*/

#ifndef PRINT_HPP_
#define PRINT_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int openWindow();
void displayShape(sf::RenderWindow *window, int _x, int _y, int _size, int _size2);
void displayBar(sf::RenderWindow *window, int _x, int _y, int _size, int _size2);
void displayText(sf::RenderWindow *window, std::string _text, int _x, int _y, int size);
void displayTitle(sf::RenderWindow *window, std::string _title, int _x, int _y, int size);

#endif /* !PRINT_HPP_ */
