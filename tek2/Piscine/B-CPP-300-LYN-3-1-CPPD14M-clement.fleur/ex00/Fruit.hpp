/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>
#include <iostream>

class Fruit
{
    public:
        Fruit(int vitamin, std::string name);
        virtual ~Fruit();

        std::string getName() const;
        int getVitamins() const;

    protected:
        int _vitamins;
        std::string const name;
    private:
};

#endif /* !FRUIT_HPP_ */
