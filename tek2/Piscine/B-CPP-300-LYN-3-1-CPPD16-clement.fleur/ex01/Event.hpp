/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-clement.fleur
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

class Event
{
    public:
        Event(unsigned int time, const std ::string &event);
        Event();
        ~Event();
        Event(const Event &other);
        Event &operator=(const Event &rhs);
        unsigned int getTime() const;
        const std ::string &getEvent() const;
        void setTime(unsigned int time);
        void setEvent(std ::string const &event);

    protected:
        unsigned int _time;
        std::string _event;
};

#endif /* !EVENT_HPP_ */
