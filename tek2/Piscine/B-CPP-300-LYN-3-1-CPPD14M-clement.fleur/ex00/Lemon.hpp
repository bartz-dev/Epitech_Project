/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-clement.fleur
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"
#include <string>

class Lemon : public Fruit {
    public:
        Lemon();
        virtual ~Lemon();

        //getter
        int getVitamins() const;
        std::string getName();

    protected:
    private:
};

#endif /* !LEMON_HPP_ */
