/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** PowerFist.hpp
*/

#ifndef POWER_FIST_D
#define POWER_FIST_D

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    public:
        explicit PowerFist();
        virtual ~PowerFist();
        
        virtual void attack() const;
};

#endif // !POWER_FIST_D