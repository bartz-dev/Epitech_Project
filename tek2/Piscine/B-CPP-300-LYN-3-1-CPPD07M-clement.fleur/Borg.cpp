/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-clement.fleur
** File description:
** Borg.cpp
*/

#include "Borg.hpp"

Borg::Ship::Ship()
{
    this->_side = 300;
    this->_maxWarp = 9;

    std::cout << "We are the Borgs. Lower your shields and"
    << " surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile" << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->core = core;
}

void Borg::Ship::checkCore()
{
    std::string data = this->core->checkReactor()->isStable() ?
    "Everything is in order." : "Critical failure imminent.";

    std::cout << data << std::endl;
}