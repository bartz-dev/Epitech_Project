/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** RadScorpion.hpp
*/

#ifndef RAD_SCORPION_D
#define RAD_SCORPION_D

#include "AEnemy.hpp"

class RadScorpion : public AEnemy
{
    int hp;
    std::string *type;

    public:
        RadScorpion();
        virtual ~RadScorpion();
};

#endif // !RAD_SCORPION_D