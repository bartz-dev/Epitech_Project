/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-clement.fleur
** File description:
** Event
*/

#include "Event.hpp"

Event::Event(unsigned int time, const std::string &event) : _time(time), _event(event)
{
}

Event::Event() : _time(0)
{
}

Event::~Event()
{
}

Event::Event(const Event &other) : _time(other._time), _event(other._event)
{
}

Event &Event::operator=(const Event &rhs)
{
    this->_time = rhs._time;
    this->_event = rhs._event;

    return *this;
}

unsigned int Event::getTime() const
{
    return this->_time;
}

const std::string &Event::getEvent() const
{
    return this->_event;
}

void Event::setTime(unsigned int time)
{
    this->_time = time;
}

void Event::setEvent(const std::string &event)
{
    this->_event = event;
}