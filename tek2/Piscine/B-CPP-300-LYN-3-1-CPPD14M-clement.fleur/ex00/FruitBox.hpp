/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
    public:
        ~FruitBox();
        FruitBox(int size);
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();

    protected:
        int _size;
        int _nbrFruit;
        FruitNode *_fruit;
};

#endif /* !FRUITBOX_HPP_ */
