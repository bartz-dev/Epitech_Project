/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** Banana
*/

#ifndef BANANA_HPP_
#define BANANA_HPP_

#include "Fruit.hpp"
#include <string>

class Banana : public Fruit
{
    public:
        Banana();
        ~Banana();

        //getter
        int getVitamins() const;
        std::string getName() const;

    protected:
    private:
};

#endif /* !BANANA_HPP_ */
