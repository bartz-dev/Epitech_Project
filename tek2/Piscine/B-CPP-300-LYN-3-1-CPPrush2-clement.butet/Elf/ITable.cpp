/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** ITable
*/

#include "ITable.hpp"

ITable::ITable()
{
    this->_onTable = 0;
}

ITable::~ITable()
{
}

ITable *ITable::createTable()
{
	return (new ITable());
}

Object *ITable::takeObject()
{
    if (!this->item) {
        std::cerr << "Error gift is empty" << std::endl;
        return nullptr;
    }
    Object *tmp = this->item;
    this->item = nullptr;

    return tmp;
}

void ITable::PushIN(Object *object)
{
    this->PutObject(object);
    std::cout << "Elfe push IN button" << std::endl;
}

void ITable::PushOUT()
{
    if (!this->item) {
        std::cerr << "Error can't push OUT button" << std::endl;
        return;
    }
    std::cout << "Elfe push OUT button" << std::endl;
}

void ITable::PutObject(Object *object)
{
    if (this->item) {
        std::cerr << "Error can't take Object because he already have one" << std::endl;
        return;
    }
    std::cout << "Object put on Table by Elf" << std::endl;
    this->item = object;
}
