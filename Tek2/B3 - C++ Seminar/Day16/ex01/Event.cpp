/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** Event
*/

#include "Event.hpp"

Event::Event(unsigned int time, const std::string &event) : _time(time), _event(event)
{
}

Event::Event() : _time(0), _event("")
{
}

Event::Event(const Event &other)
{
    _time = other._time;
    _event = other._event;
}

Event::~Event()
{
}

Event &Event::operator=(const Event &other)
{
    _time = other._time;
    _event = other._event;

    return (*this);
}

unsigned int Event::getTime() const { return (_time); }

const std::string &Event::getEvent() const { return (_event); }

void Event::setTime(unsigned int time) { _time = time; }

void Event::setEvent(const std::string &event) { _event = event; }