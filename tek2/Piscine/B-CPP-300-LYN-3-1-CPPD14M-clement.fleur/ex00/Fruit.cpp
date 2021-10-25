/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(int vitamine, std::string name) : _vitamins(vitamine), name(name)
{
}

Fruit::~Fruit()
{
}

std::string Fruit::getName() const
{
    return this->name;
}

int Fruit::getVitamins() const
{
    return this->_vitamins;
}
