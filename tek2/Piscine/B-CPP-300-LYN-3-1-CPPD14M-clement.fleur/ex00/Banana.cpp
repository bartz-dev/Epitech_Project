/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** Banana
*/

#include "Banana.hpp"

Banana::Banana() : Fruit(5, "banana")
{
}

Banana::~Banana()
{
}

std::string Banana::getName() const
{
    return this->name;
}

int Banana::getVitamins() const
{
    return this->_vitamins;
}
