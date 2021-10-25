/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_size = size;
    this->_fruit = nullptr;
    this->_nbrFruit = 0;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return this->_nbrFruit;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *tmp = this->_fruit;
    FruitNode *elem;
    int size = 1;

    if (size >= this->_size)
      return(false);
    if (this->_fruit == nullptr)
    {
        this->_fruit = new FruitNode;
        this->_fruit->data = f;
        this->_fruit->next = NULL;
        this->_nbrFruit++;
        return(true);
    }
    tmp = this->_fruit;
    while (tmp->next != nullptr)
    {
        if ((tmp->data == f) || (size >= this->_size))
            return(false);
        size++;
        tmp = tmp->next;
    }
    if (size >= this->_size || tmp->data == f)
        return(false);
    elem = new FruitNode;
    elem->data = f;
    elem->next = nullptr;
    tmp->next = elem;
    _nbrFruit++;
    return(true);
}

Fruit *FruitBox::pickFruit()
{
    Fruit *received_fruit;
    FruitNode *tmp;

    if (this->_fruit == nullptr)
        return nullptr;
    received_fruit = this->_fruit->data;
    tmp = this->_fruit;
    this->_fruit = this->_fruit->next;
    delete tmp;
    _nbrFruit--;
    return(received_fruit);
}

FruitNode *FruitBox::head()
{
    return this->_fruit;
}