/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** ConveyorBelt
*/

#include "ConveyorBelt.hpp"

IConveyorBelt::IConveyorBelt()
{
    this->_onBelt = 0;
}

IConveyorBelt::~IConveyorBelt()
{
}

Object *IConveyorBelt::takeObject()
{
    if (!this->item) {
        std::cerr << "error finir msg" << std::endl;
        return (nullptr);
    }
    Object *tmp =this->item;
    this->item = nullptr;
    return (tmp);
}

void IConveyorBelt::putObject(Object *object)
{
    if (this->item) {
        std::cerr << "error finir msg" << std::endl;
        return;
    } else {
        std::cout << "Elfe put " << object->getTitle() << std::endl;
        this->item = object;
    }
}

IConveyorBelt *IConveyorBelt::createConveyorBelt()
{
    return (new IConveyorBelt());
}

void IConveyorBelt::PushIN(Object *object)
{
    this->putObject(object);
    std::cout << "Elfe push IN button" << std::endl;
}

void IConveyorBelt::PushOUT()
{
    if (!this->item) {
        std::cerr << "msg error" << std::endl;
        return;
    }
    std::cout << "Elfe push OUT button" << std::endl;
}