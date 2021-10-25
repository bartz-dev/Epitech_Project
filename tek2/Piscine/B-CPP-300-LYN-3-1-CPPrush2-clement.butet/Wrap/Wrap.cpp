/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &name) : Object(name)
{
    this->object = NULL;
    this->_isopen = false;
}

Wrap::~Wrap()
{
}

Wrap &Wrap::operator=(Object *object)
{
    this->object->setTitle(object->getTitle());

    return (*this);
}

void Wrap::setIsOpen(int Isopen)
{
    this->_isopen = Isopen;
}

Wrap &Wrap::wrapMeThat(const Object &_Toy, const Object &Gift_Paper)
{
    if (this->object) {
        std::cout << "Already have a gift!" << std::endl;
        return *this;
    }
    if (this->_isopen == false) {
        std::cout << "It's not open" << std::endl;
        return *this;
    }
    if (this->_isopen == true && this->object == nullptr) {
        this->toy = _Toy.getTitle();
        this->box = Gift_Paper.getTitle();
        std::cout << this->toy << "Has been wrapped" << std::endl;
    }
    return *this;
}

Object *Wrap::getObject()
{
    return this->object;
}

const std::string Wrap::getToy()
{
    return this->toy;
}

const std::string Wrap::getBox()
{
    return this->box;
}
