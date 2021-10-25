/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** SuperMutant.hpp
*/

#ifndef MUTANT_D
#define MUTANT_D

#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
    int hp;
    std::string *type;

    public:
        SuperMutant();
        virtual ~SuperMutant();
        void takeDamage(int damage);
};

#endif // !MUTANT_D