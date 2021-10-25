/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** AWeapon.cpp
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : damage(damage), ap(apcost)
{
    this->name = new std::string(name);
}

AWeapon::~AWeapon()
{
}

std::string &AWeapon::getName() const
{
    return *this->name;
}

int AWeapon::getAPCost() const
{
    return this->ap;
}

int AWeapon::getDamage() const
{
    return this->damage;
}