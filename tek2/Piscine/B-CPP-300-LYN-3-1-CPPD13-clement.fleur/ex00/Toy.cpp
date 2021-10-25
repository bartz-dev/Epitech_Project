/*
** EPITECH PROJECT, 2021
** toy
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy")
{
}

Toy::Toy(ToyType type, std::string const &name, std::string const &ascii) : type(type), name(name), picture(ascii)
{
}

Toy::~Toy()
{
}

const std::string &Toy::getName() const
{
    return this->name;
}

const std::string &Toy::getAscii() const
{
    return this->picture.data;
}

int Toy::getType() const
{
    return this->type;
}

bool Toy::setAscii(const std::string &ascii)
{
    if (this->picture.getPictureFromFile(ascii))
        return true;
    return false;
}

void Toy::setName(const std::string &name)
{
    this->name = name;
}
