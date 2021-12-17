/*
** EPITECH PROJECT, 2021
** print.cpp
** File description:
** 
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void displayShape(sf::RenderWindow *window, int _x, int _y, int _size, int _size2)
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(_size, _size2));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(4);
    rect.setOutlineColor(sf::Color::Cyan);
    rect.setPosition(_x, _y);
    window->draw(rect);
}

void displayBar(sf::RenderWindow *window, int _x, int _y, int _size, int _size2)
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(_size, _size2));
    rect.setFillColor(sf::Color::Yellow);
    rect.setPosition(_x, _y);
    window->draw(rect);
}

void displayText(sf::RenderWindow *window, std::string _text, int _x, int _y, int size)
{
    sf::Font font;
    font.loadFromFile("SFML/Affichage/batman.ttf");
    sf::Text text(_text, font, size);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(sf::Vector2f(_x, _y));
    window->draw(text);
}

void displayTitle(sf::RenderWindow *window, std::string _title, int _x, int _y, int size)
{
    sf::Font font;
    font.loadFromFile("SFML/Affichage/batman.ttf");
    sf::Text text(_title, font, size);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(sf::Vector2f(_x, _y));
    window->draw(text);
}
    // displayShape(window, 320, 275, 1270, 250);
    // displayShape(window, 320, 600, 600, 250);
    // displayShape(window, 990, 600, 600, 250);
    // displayShape(window, 420, 700, 400, 50);
    // displayBar(window, 426, 706, 338, 38);
    // displayTitle(window, "Hostname :", 200, 60, 25);
    // displayText(window, "pc-29.home", 415, 60, 25);
    // displayTitle(window, "Username :", 680, 60, 25);
    // displayText(window, "trominger", 890, 60, 25);
    // displayTitle(window, "Date :", 590, 150, 20);
    // displayText(window, "Sat Jan 23 17:30:49 2021", 680, 150, 20);
    // displayTitle(window, "CPU module :", 350, 225, 25);
    // displayText(window, "6.3% (Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz)", 615, 230, 23);
    // displayTitle(window, "Frequency :", 370, 285, 23);
    // displayText(window, "799.99Hz", 590, 285, 23);
    // displayTitle(window, "CPU 1 :", 450, 345, 21);
    // displayText(window, "5.51%", 555, 345, 21);
    // displayTitle(window, "CPU 2 :", 450, 395, 21);
    // displayText(window, "5.51%", 565, 395, 21);
    // displayTitle(window, "CPU 3 :", 450, 445, 21);
    // displayText(window, "5.51%", 565, 445, 21);
    // displayTitle(window, "CPU 4 :", 750, 345, 21);
    // displayText(window, "5.51%", 865, 345, 21);
    // displayTitle(window, "CPU 5 :", 750, 395, 21);
    // displayText(window, "5.51%", 865, 395, 21);
    // displayTitle(window, "CPU 6 :", 750, 445, 21);
    // displayText(window, "5.51%", 865, 445, 21);
    // displayTitle(window, "CPU 7 :", 1050, 345, 21);
    // displayText(window, "5.51%", 1165, 345, 21);
    // displayTitle(window, "CPU 8 :", 1050, 395, 21);
    // displayText(window, "5.51%", 1165, 395, 21);
    // displayTitle(window, "Ram module :", 350, 550, 25);
    // displayText(window, "7.13GB / 8.21GB (86%) - 1.08GB free", 365, 610, 23);
    // displayTitle(window, "Network module :", 1015, 550, 25);
    // displayTitle(window, "Packages sent :", 1015, 630, 23);
    // displayText(window, "0  (0 KB)", 1380, 630, 23);
    // displayTitle(window, "\\(per second) :", 1015, 680, 23);
    // displayText(window, "0  (0 Bytes)", 1380, 680, 23);
    // displayTitle(window, "Packages received :", 1015, 730, 23);
    // displayText(window, "0  (0 MB)", 1380, 730, 23);
    // displayTitle(window, "\\(per second) :", 1015, 780, 23);
    // displayText(window, "0  (0 Bytes)", 1380, 780, 23);
    // displayTitle(window, "Number of core :", 800, 920, 23);
    // displayText(window, "8", 1085, 920, 23);
    // displayTitle(window, "Operating System :", 250, 920, 25);
    // displayText(window, "Linux", 610, 920, 25);
    // displayTitle(window, "Kernel Version :", 250, 955, 16);
    // displayText(window, "5.3.16-200.fc30.x86_64", 445, 955, 16);