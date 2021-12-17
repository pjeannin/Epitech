/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "AEvent.hpp"

RType::AEvent::AEvent() noexcept {
    this->_keyEvent = std::vector<bool>(KEY_NUMBER, false);
}

const std::vector<bool> &RType::AEvent::getKeyEvent() const noexcept { return _keyEvent; }

const RType::AEvent::Controller &RType::AEvent::getControllerEvent() const noexcept { return _controllerEvent; }

bool RType::AEvent::isControllerPlugged() const noexcept { return _controller; }

void RType::AEvent::resetEvents() noexcept
{
    for (unsigned int i = 0; i < this->_keyEvent.size(); ++i)
        this->_keyEvent[i] = false;
    this->_controllerEvent.buttonA = false;
    this->_controllerEvent.buttonB = false;
    this->_controllerEvent.JoystickX = 0.0f;
    this->_controllerEvent.JoystickY = 0.0f;
}
