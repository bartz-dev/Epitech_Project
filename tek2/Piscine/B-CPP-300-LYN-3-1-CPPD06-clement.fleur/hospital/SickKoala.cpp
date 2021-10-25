/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** SickKoala.cpp
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
    this->name.clear();
}

void SickKoala::poke()
{
    std::cout << "Mr." <<  this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (!str.compare("Mars")) {
        std::cout << "Mr."<< this->name << ": Mars, and it kreogs!"
        << std::endl;
        return true;
    } else if (!str.compare("Kinder")) {
        std::cout << "Mr."<< this->name << ": There is a toy inside!"
        << std::endl;
        return true;
    }
    std::cout << "Mr." << this->name << ": Goerkreog!"
    << std::endl;
    return false;
}

void SickKoala::overDrive(std::string str)
{
    size_t pos;

    while ((pos = str.find("Kreog!")) != std::string::npos) {
        str.replace(pos, 6, "1337!");
    }
    std::cout << "Mr." << this->name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return this->name;
}