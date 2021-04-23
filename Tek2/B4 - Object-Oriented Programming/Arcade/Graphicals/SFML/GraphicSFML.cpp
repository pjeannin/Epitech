/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin [WSL: Ubuntu]
** File description:
** GraphicSFML
*/

#include "GraphicSFML.hpp"


GraphicSFML::GraphicSFML(): window(sf::VideoMode(1920, 1080), "Arcade")
{
    if (!font.loadFromFile("./assets/font.ttf"))
        throw(Error ("Can't load the font."));
}

GraphicSFML::~GraphicSFML()
{
    window.close();
}

void GraphicSFML::refreshScreen()
{
    window.display();
}

void GraphicSFML::clearScreen()
{
    window.clear(sf::Color(0, 0, 0, 1));
}

void GraphicSFML::drawRect(const Rect &rect)
{
    sf::RectangleShape rectangle;
    sf::Color color(rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);

    rectangle.setSize(sf::Vector2f((rect.size.x * window.getSize().x / 100), (rect.size.y * window.getSize().y / 100)));
    rectangle.setFillColor(color);
    rectangle.setPosition(rect.pos.x * window.getSize().x / 100, rect.pos.y * window.getSize().y / 100);
    window.draw(rectangle);
}

void GraphicSFML::drawCircle(const Circle &circle)
{
    sf::CircleShape circ;
    sf::Color color(circle.color.red, circle.color.green, circle.color.blue, circle.color.alpha);

    circ.setRadius(circle.radius * window.getSize().x / 100);
    circ.setFillColor(color);
    circ.setPosition((circle.pos.x - circle.radius) * window.getSize().x / 100, (circle.pos.y - circle.radius) * window.getSize().y / 100);
    window.draw(circ);
}

void GraphicSFML::drawText(const Text &text)
{
    sf::Text myText;
    sf::Color color (text.color.red, text.color.green, text.color.blue, text.color.alpha);

    myText.setFont(font);
    myText.setCharacterSize((text.size.x / 10) * window.getSize().x / 100);
    myText.setPosition(text.pos.x * window.getSize().x / 100, text.pos.y * window.getSize().y / 100);
    myText.setFillColor(color);
    myText.setString(text.getText());
    window.draw(myText);
}

void GraphicSFML::drawSprite(const Sprite &sprite)
{
    sf::Texture text;
    sf::Sprite spri;

    if (!text.loadFromFile(sprite.getTexturePath()))
        throw("Can't load texture.");

    spri.setTexture(text);
    spri.setPosition(sprite.pos.x * window.getSize().x / 100, sprite.pos.y * window.getSize().y / 100);
    window.draw(spri);
}

bool GraphicSFML::isOperational() {return true;}

Event GraphicSFML::handleEvent()
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                return Event::up;
            if (event.key.code == sf::Keyboard::Down)
                return Event::down;
            if (event.key.code == sf::Keyboard::Right)
                return Event::right;
            if (event.key.code == sf::Keyboard::Left)
                return Event::left;
            if (event.key.code == sf::Keyboard::Escape)
                return Event::menu;
            if (event.key.code == sf::Keyboard::Return)
                return Event::enter;
            if (event.key.code == sf::Keyboard::W)
                return Event::prev_graphic;
            if (event.key.code == sf::Keyboard::X)
                return Event::next_graphic;
            if (event.key.code == sf::Keyboard::C)
                return Event::prev_game;
            if (event.key.code == sf::Keyboard::V)
                return Event::next_game;
            if (event.key.code == sf::Keyboard::R)
                return Event::restart;
        }
        if (event.type == sf::Event::Closed)
            return Event::quit;
    }
    return Event::unknown;
}

extern "C"
{
    GraphicSFML *entry()
    {
        return new GraphicSFML;
    }
}