/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Box
*/

#include "Box.hpp"

Box::Box(std::string const& name) : Wrap(name)
{
}

Box::~Box()
{
}

bool Box::isOpen() const
{
    std::cout << "The box is open" << std::endl;
    return (this->_open);
}

void Box::CloseMe()
{
    std::cout << "The box is close" << std::endl;
    this->_open = false;
}

void Box::OpenMe()
{
    this->_open = true;
}