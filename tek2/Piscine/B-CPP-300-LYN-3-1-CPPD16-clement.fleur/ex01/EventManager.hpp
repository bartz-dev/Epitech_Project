/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-clement.fleur
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "Event.hpp"
#include <list>
#include <iostream>

class EventManager {
    public:
        EventManager();
        ~EventManager();
        EventManager(EventManager const &other);
        EventManager &operator =(EventManager const & rhs);

        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;

        void addTime(unsigned int time);
        void addEventList(const std::list<Event> &events);
        static bool compareTime(const Event &first, const Event &second);
        static bool compareList(const Event &first, const Event &second);

    protected:
        unsigned int _time;
        std::list<Event> _event;
};

#endif /* !EVENTMANAGER_HPP_ */
