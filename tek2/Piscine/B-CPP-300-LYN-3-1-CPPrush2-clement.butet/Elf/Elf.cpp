/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Elf
*/

#include "Elf.hpp"

Elf::Elf()
{
    this->_hold = false;
}

Elf::~Elf()
{
}

void Elf::take(Object &object)
{
    if (this->_hold == false) {
        std::cout << "Elf take the" << object.getTitle() << std::endl;
        this->_hold = true;
    } else {
        std::cout << "Elf already hold an object" << std::endl;
    }
}

void Elf::put(Object &object)
{
    if (this->_hold == true) {
        std::cout << "Elf put the" << object.getTitle() << std::endl;
        this->_hold = false;
    } else {
        std::cout << "Elf don't have object" << std::endl;
    }
}