/*
** EPITECH PROJECT, 2021
** buzz
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file) : Toy(BUZZ, name, file)
{
}

Buzz::Buzz(const Buzz &buzz) : Toy(buzz)
{
}

Buzz::~Buzz()
{
}