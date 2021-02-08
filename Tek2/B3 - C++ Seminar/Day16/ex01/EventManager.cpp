/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** EventManager
*/

#include "EventManager.hpp"

EventManager::EventManager() : _currentTime(0)
{
}

EventManager::~EventManager()
{
}

EventManager::EventManager(const EventManager &other)
{
    _currentTime = other._currentTime;
    _eventList = other._eventList;
}

EventManager &EventManager::operator=(const EventManager &other)
{
    _currentTime = other._currentTime;
    _eventList = other._eventList;

    return (*this);
}
bool sortEvent(const Event &a, const Event &b)
{
    if (a.getTime() <= b.getTime())
        return (true);
    return (false);
}

void EventManager::addEvent(const Event &event)
{
    if (event.getTime() < _currentTime)
        return;
    _eventList.push_back(event);
    _eventList.sort(sortEvent);
}

void EventManager::removeEventsAt(unsigned int time)
{
    for (std::list<Event>::iterator iterator = _eventList.begin(); iterator != _eventList.end(); ++iterator)
        if (iterator->getTime() == time) {
            iterator = _eventList.erase(iterator);
            iterator--;
        }
}

void EventManager::dumpEvents() const
{
    for (std::list<Event>::const_iterator iterator = _eventList.begin(); iterator != _eventList.end(); ++iterator)
        std::cout << iterator->getTime() << ": " << iterator->getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (std::list<Event>::const_iterator iterator = _eventList.begin(); iterator != _eventList.end(); ++iterator)
        if (iterator->getTime() == time)
            std::cout << iterator->getTime() << ": " << iterator->getEvent() << std::endl;
}


void dumpEventAtfordelete(unsigned int time, std::list<Event> &list)
{
    for (std::list<Event>::iterator iterator = list.begin(); iterator != list.end(); ++iterator)
        if (iterator->getTime() == time)
            std::cout << iterator->getEvent() << std::endl;
}

void EventManager::addTime(unsigned int time)
{
    for (unsigned int i = _currentTime; i <= _currentTime + time; ++i) {
        for (std::list<Event>::const_iterator iterator = _eventList.begin(); iterator != _eventList.end(); ++iterator)
            if (iterator->getTime() == i) {
                std::cout << iterator->getEvent() << std::endl;
                iterator = _eventList.erase(iterator);
                iterator--;
            }
    }
    _currentTime += time;
}

void EventManager::addEventList(std::list<Event> &events)
{
    for (std::list<Event>::iterator iterator = events.begin(); iterator != events.end(); ++iterator)
        addEvent(*iterator);
}