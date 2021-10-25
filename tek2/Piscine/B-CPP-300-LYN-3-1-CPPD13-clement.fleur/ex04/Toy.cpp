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

Toy::Toy(const Toy &toy) : type(toy.type), name(toy.name), picture(toy.picture)
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

Toy &Toy::operator=(const Toy &toy)
{
    this->type = toy.type;
    this->name = toy.name;
    this->picture = toy.picture;

    return *this;
}

void Toy::speak(std::string const &data)
{
    std::cout << this->getName() << " \"" << data << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Toy const &toy)
{
    os << toy.getName() << std::endl << toy.getAscii() << std::endl;

    return os;
}

Toy &Toy::operator<<(std::string const &new_data)
{
    this->picture.data = new_data;

    return *this;
}