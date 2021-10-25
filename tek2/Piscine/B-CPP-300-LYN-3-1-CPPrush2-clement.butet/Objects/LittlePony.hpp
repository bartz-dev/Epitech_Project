/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** LittlePony.hpp
*/

#ifndef LITTLE_PONEY_D
#define LITTLE_PONEY_D

#include "Toy.hpp"
#include <string>

class LittlePony : public Toy
{
    public:
        LittlePony(const std::string &name);
        ~LittlePony();

        //action
        void isTaken();

    protected:
    private:
};

#endif // !LITTLE_PONEY_D