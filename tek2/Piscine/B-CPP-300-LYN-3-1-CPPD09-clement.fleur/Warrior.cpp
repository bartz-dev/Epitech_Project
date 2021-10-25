/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Warrior.cpp
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) : Character(name, level), weaponName("hammer")
{
    this->name = name;
    this->level = level;
    this->strength = 12;
    this->stamina = 12;
    this->intelligence = 6;
    this->spirit = 5;
    this->agility = 7;

    std::cout << "I'm " << this->name
    << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack()
{
    if (this->energy >= 30) {
        this->energy -= 30;
        std::cout << this->name << " strikes with his " << this->weaponName << std::endl;
        return 20 + this->strength;
    }
    std::cout << this->name << " out of power" << std::endl;
    return 0;
}

void Warrior::Heal()
{
    this->pv += 50;
    if (this->pv > 100)
        this->pv = 100;
    std::cout << this->name << " takes a potion" << std::endl;
}

int Warrior::RangeAttack()
{
    if (this->energy >= 10) {
        this->energy -= 10;
        std::cout << this->name << " intercepts" << std::endl;
        this->Range = Character::CLOSE;
        return 0;
    }
    std::cout << this->name << " out of power" << std::endl;
    return 0;
}

void Warrior::RestorePower()
{
    this->energy = 100;
    std::cout << this->name << " eats" << std::endl;
}