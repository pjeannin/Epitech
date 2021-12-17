/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SfmlEvent.hpp"

#include <utility>

RType::SfmlEvent::SfmlEvent(std::shared_ptr<sf::RenderWindow>  window) noexcept : AEvent(), _window(std::move(window)) {
    _keys = std::vector<sf::Keyboard::Key> {
        sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right,
        sf::Keyboard::Space, sf::Keyboard::Return, sf::Keyboard::Escape,
        sf::Keyboard::Num0, sf::Keyboard::Num1, sf::Keyboard::Num2, sf::Keyboard::Num3, sf::Keyboard::Num4, sf::Keyboard::Num5, sf::Keyboard::Num6, sf::Keyboard::Num7, sf::Keyboard::Num8, sf::Keyboard::Num9,
        sf::Keyboard::A, sf::Keyboard::B, sf::Keyboard::C, sf::Keyboard::D, sf::Keyboard::E, sf::Keyboard::F, sf::Keyboard::G, sf::Keyboard::H, sf::Keyboard::I,
        sf::Keyboard::J, sf::Keyboard::K, sf::Keyboard::L, sf::Keyboard::M, sf::Keyboard::N, sf::Keyboard::O, sf::Keyboard::P, sf::Keyboard::Q, sf::Keyboard::R,
        sf::Keyboard::S, sf::Keyboard::T, sf::Keyboard::U, sf::Keyboard::V, sf::Keyboard::W, sf::Keyboard::X, sf::Keyboard::Y, sf::Keyboard::Z,
        sf::Keyboard::Comma, sf::Keyboard::BackSpace
    };
    _controllerEvent.JoystickX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    _controllerEvent.JoystickY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    _controllerEvent.buttonA = sf::Joystick::isButtonPressed(0, 0);
    _controllerEvent.buttonB = sf::Joystick::isButtonPressed(0, 1);
}

void RType::SfmlEvent::keyboard(const sf::Event &event) noexcept
{
    for (std::size_t i = 0; i < _keys.size(); ++i)
        if (event.key.code == _keys[i])
            _keyEvent[i] = true;
}

void RType::SfmlEvent::keyboardR(const sf::Event &event) noexcept
{
    if (event.key.code == sf::Keyboard::Left)
        _keyEvent[LEFT_RELEASE] = true;
    if (event.key.code == sf::Keyboard::Right)
        _keyEvent[RIGHT_RELEASE] = true;
    if (event.key.code == sf::Keyboard::Up)
        _keyEvent[UP_RELEASE] = true;
    if (event.key.code == sf::Keyboard::Down)
        _keyEvent[DOWN_RELEASE] = true;
}

void RType::SfmlEvent::update() noexcept
{
    sf::Event event{};
    resetEvents();
    _controller = sf::Joystick::isConnected(0);
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window->close();
        if (event.type == sf::Event::KeyPressed)
            keyboard(event);
        if (event.type == sf::Event::KeyReleased)
            keyboardR(event);
    }
    _controllerEvent.JoystickX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    _controllerEvent.JoystickY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    _controllerEvent.buttonA = sf::Joystick::isButtonPressed(0, 0);
    _controllerEvent.buttonB = sf::Joystick::isButtonPressed(0, 1);
}
