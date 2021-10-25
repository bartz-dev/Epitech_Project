/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** Sorcerer.cpp
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
    std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->name << ", " << this->title
    << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const
{
    return this->name;
}

std::string Sorcerer::getTitle() const
{
    return this->title;
}

void Sorcerer::polymorph(const Victim &victim)
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &peon)
{
    peon.getPolymorphed();
}

std::ostream& operator<<(std::ostream &os, const Sorcerer &sorcers)
{
    return os << "I am " << sorcers.getName() << ", " << sorcers.getTitle()
    << ", and I like ponies!" << std::endl;
}