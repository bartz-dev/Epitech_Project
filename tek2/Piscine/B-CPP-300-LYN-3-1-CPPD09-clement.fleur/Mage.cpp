/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** fluffy.cpp
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->strength = 6;
    this->stamina = 6;
    this->intelligence = 12;
    this->spirit = 11;
    this->agility = 7;

    std::cout << this->name << " teleported" << std::endl;
}

void Mage::RestorePower()
{
    this->energy = 50 + this->intelligence;
    if (this->energy > 100)
        this->energy = 100;
    std::cout << this->name << " takes a mana potion" << std::endl;
}

void Mage::Heal()
{
    this->pv += 50;
    if (this->pv > 100)
        this->pv = 100;
    std::cout << this->name << " takes a potion" << std::endl;

}
int Mage::CloseAttack()
{
    if (this->energy >= 10) {
        this->energy -= 10;
        std::cout << this->name << " blinks" << std::endl;
    }
    this->Range = Character::RANGE;
    return 0;

}

int Mage::RangeAttack()
{
    if (this->energy >= 25) {
        this->energy -= 25;
        std::cout << this->name << " launches a fire ball" << std::endl;
        return 20 + this->spirit;
    }
    return 0;
}