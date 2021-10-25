/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon() : Fruit(3, "lemon")
{
}

Lemon::~Lemon()
{
}

std::string Lemon::getName()
{
    return this->name;
}

int Lemon::getVitamins() const
{
    return this->_vitamins;
}