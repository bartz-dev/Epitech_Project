/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Toy
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include "Object.hpp"

#ifndef TOY_HPP_
#define TOY_HPP_

class Toy : public Object
{
    public:
        Toy(std::string title = "");
        virtual ~Toy();
        virtual void isTaken() = 0;

        std::string getName();

    protected:

};

#endif /* !TOY_HPP_ */