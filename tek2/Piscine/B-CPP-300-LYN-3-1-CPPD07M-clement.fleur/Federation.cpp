/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-clement.fleur
** File description:
** Federation.cpp
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship (int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name.assign(name);
    this->_maxWarp = maxWarp;
    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width
    << " m in width." << std::endl;
    std::cout << "It can go to Warp " <<  this->_maxWarp << "!" << std::endl;
}

Federation::Ship::Ship (int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;

    std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::string stability = this->core->checkReactor()->isStable() ?
    "stable at the time." : "unstable at the time.";
    std::cout << this->_name << ": The core is " << stability << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string stability = this->core->checkReactor()->isStable() ?
    "stable at the time." : "unstable at the time.";
    std::cout << "USS " << this->_name << ": The core is " << stability << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
    this->_age = 0;
}

int Federation::Starfleet::Captain::getAge()
{
    return this->_age;
}

std::string Federation::Starfleet::Captain::getName()
{
    return this->_name;
}

void Federation::Starfleet::Captain::setAge(int new_age)
{
    this->_age = new_age;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    this->captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS "
    << this->_name << "." <<std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;

    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}