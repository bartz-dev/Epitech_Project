/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Mage(name, level)
{
    this->strength = 4;
    this->stamina = 4;
    this->intelligence = 42;
    this->spirit = 21;
    this->agility = 2;

    std::cout << this->name << " enters in the order" << std::endl;
}

void Priest::RestorePower()
{
    this->energy = 50 + this->intelligence;
    std::cout << this->name << " takes a mana potion" << std::endl;
}

void Priest::Heal()
{
    if (this->energy > 10) {
        this->pv += 70;
        std::cout << this->name << " casts a little heal spell" << std::endl;
    }
    if (this->pv > 100)
        this->pv = 100;
}

int Priest::CloseAttack()
{
    this->Range = Character::RANGE;
    if (this->energy >= 10) {
        this->energy -= 10;
        std::cout << this->name << " uses a spirit explosion" << std::endl;
        return 10 + this->spirit;
    }
    std::cout << this->name << " out of power" << std::endl;
    return 0;
}

int Priest::RangeAttack()
{
    if (this->energy >= 25) {
        this->energy -= 25;
        std::cout << this->name << " launches a fire ball" << std::endl;
        return 20 + this->spirit;
    }
    return 0;
}