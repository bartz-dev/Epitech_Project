/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** PlasmaRifle.hpp
*/

#ifndef PLASMA_D
#define PLASMA_D

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        explicit PlasmaRifle();
        virtual ~PlasmaRifle();

        virtual void attack() const;
};

#endif // !PLASMA_D