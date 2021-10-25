/*
** EPITECH PROJECT, 2021
** woody
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file) : Toy(WOODY, name, file)
{
}

Woody::Woody(const Woody &woody) : Toy(woody)
{
}

Woody::~Woody()
{
}

void Woody::speak(std::string const &data)
{
    std::cout << "WOODY: " << this->getName() << " \"" << data << "\"" << std::endl;
}