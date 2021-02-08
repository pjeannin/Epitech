/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include <list>
#include <iostream>
#include "Event.hpp"

class EventManager {
    public:
        EventManager();
        ~EventManager();
        EventManager(const EventManager &other);
        EventManager &operator=(const EventManager &other);
        void addEvent(const Event &event);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(std::list<Event> &events);

    protected:
    private:
        std::list<Event> _eventList;
        unsigned int _currentTime;
};

#endif /* !EVENTMANAGER_HPP_ */
