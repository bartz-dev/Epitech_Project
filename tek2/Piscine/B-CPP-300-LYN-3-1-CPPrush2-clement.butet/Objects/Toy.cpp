/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Toy
*/

#include "Toy.hpp"
#include "Object.hpp"

Toy::Toy(std::string const name) : Object(name)
{
}

std::string Toy::getName()
{
    return (this->_title);
}

Toy::~Toy()
{
}