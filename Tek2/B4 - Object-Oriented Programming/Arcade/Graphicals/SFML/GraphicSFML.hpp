/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin [WSL: Ubuntu]
** File description:
** GraphicSFML
*/

#ifndef GRAPHICSFML_HPP_
#define GRAPHICSFML_HPP_

#include "../../interfaces/IGraphics.hpp"
#include "../../Core/Error.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GraphicSFML: public IGraphic {
    public:
        GraphicSFML();
        ~GraphicSFML();
        void drawRect(const Rect &rect);
        void drawCircle(const Circle &circle);
        void drawSprite(const Sprite &sprite);
        void drawText(const Text &text);
        void refreshScreen();
        void clearScreen();
        bool isOperational();
        Event handleEvent();

        sf::RenderWindow window;
        sf::Event event;
        sf::Font font;
    protected:
    private:
};

#endif /* !GRAPHICSFML_HPP_ */
