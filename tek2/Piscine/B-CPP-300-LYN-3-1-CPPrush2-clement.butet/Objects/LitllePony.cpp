/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** LitllePony.cpp
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &name) : Toy(name)
{
    this->_title = "happy pony";
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
    std::cout << "yo man" << std::endl;
}