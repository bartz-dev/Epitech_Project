/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** AWeapon.hpp
*/

#ifndef AWEAPON_D
#define AWEAPON_D

#include <string>
#include <iostream>

class AWeapon
{
    private:
        std::string *name;
        int damage;
        int ap;

    public:
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon();
        std::string  &getName() const;

        //getter
        int getAPCost() const;
        int getDamage() const;

        virtual void attack() const = 0;
};

#endif // !AWEAPON_D