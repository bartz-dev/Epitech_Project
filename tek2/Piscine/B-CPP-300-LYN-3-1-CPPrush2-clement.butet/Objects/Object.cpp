/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(const std::string &title) : _title(title)
{
}

Object::~Object()
{
}

void Object::setTitle(const std::string &name)
{
    this->_title = name;
}

const std::string Object::getTitle() const
{
    return this->_title;
}