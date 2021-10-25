/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-clement.fleur
** File description:
** EventManager
*/

#include "EventManager.hpp"

EventManager::EventManager() : _time(0)
{
}

EventManager::~EventManager()
{
}

EventManager::EventManager(EventManager const &other)
{
    this->_event = other._event;
    this->_time = other._time;
}

EventManager &EventManager::operator=(EventManager const &rhs)
{
    this->_event = rhs._event;
    this->_time = rhs._time;

    return *this;
}

bool EventManager::compareTime(const Event &first, const Event &second)
{
    return first.getTime() <= second.getTime() ? true : false;
}

void EventManager::addEvent(const Event &e)
{
    _event.push_back(e);
    _event.sort(compareTime);
}

void EventManager::removeEventsAt(unsigned int time)
{
    std::list<Event>::const_iterator it = _event.begin();

    while (it != _event.end()) {
        if (it->getTime() == time) {
            it = _event.erase(it);
            it--;
        }
        it++;
    }
}

void EventManager::dumpEvents() const
{
    std::list<Event>::const_iterator it = _event.begin();

    while (it != _event.end()) {
        if (it->getTime() > _time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        it++;
    }

}

void EventManager::dumpEventAt(unsigned int time) const
{
    std::list<Event>::const_iterator it = _event.begin();

    while (it != _event.end()) {
        if (it->getTime() == time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        it++;
    }
}

void EventManager::addTime(unsigned int time)
{
    std::list<Event>::const_iterator it = _event.begin();


    while (it != _event.end() && it->getTime() <= _time + time) {
        std::cout << it->getEvent() << std::endl;
        it++;
    }
    _time += time;
    time = _time;
    _event.remove_if ([time](const Event &event) {
        return event.getTime() < time;
    });
}

bool EventManager::compareList(const Event &first, const Event &second)
{
    if (first.getTime() < second.getTime())
        return false;
    return true;
}

void EventManager::addEventList(const std::list<Event> &events)
{
    for (std::list<Event>::const_iterator itr = events.begin(); itr != events.end(); ++itr)
        if ((*itr).getTime() > _time)
            _event.push_back(*itr);
    _event.sort([] (const Event &first, const Event &second) {
        return first.getTime() < second.getTime() ? false : false;
    });
}
