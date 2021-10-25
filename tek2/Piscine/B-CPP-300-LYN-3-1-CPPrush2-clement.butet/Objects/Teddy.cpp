/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Teddy.cpp
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string const &name) : Toy(name)
{
    this->_title = "cuddles";
}

Teddy::~Teddy()
{

}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
}