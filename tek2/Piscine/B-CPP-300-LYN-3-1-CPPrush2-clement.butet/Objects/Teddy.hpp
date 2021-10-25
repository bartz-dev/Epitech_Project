/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Teddy.hpp
*/

#ifndef TEDDY_D
#define TEDDY_D

#include "Toy.hpp"

class Teddy : public Toy
{
    public:
        Teddy(std::string const &name);
        ~Teddy();

        //action
        void isTaken();

};

#endif // !TEDDY_D