/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Charactere.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->name = name;
    this->level = level;
    this->pv = 100;
    this->energy = 100;
    this->strength = 5;
    this->stamina = 5;
    this->intelligence = 5;
    this->spirit = 5;
    this->agility = 5;

    std::cout << this->name << " Created" << std::endl;
}

int Character::getLvl() const
{
    return this->level;
}

int Character::getPower() const
{
    return this->energy;
}

int Character::getPv() const
{
    return this->pv;
}

const std::string &Character::getName() const
{
    return this->name;
}

int Character::CloseAttack()
{
    if (this->energy >= 10) {
        this->energy -= 10;
        std::cout << this->name << " strikes with a wooden stick" << std::endl;
        return 10 + this->strength;
    }
    std::cout << this->name << " out of power" << std::endl;
    return 0;
}

void Character::Heal()
{
    this->pv += 50;
    if (this->pv > 100)
        this->pv = 100;
    std::cout << this->name << " takes a potion" << std::endl;
}

int Character::RangeAttack()
{
    if (this->energy >= 10) {
        this->energy -= 10;
        std::cout << this->name << " tosses a stone" << std::endl;
        return 5 + this->strength;
    }
    std::cout << this->name << " out of power" << std::endl;
    return 0;
}

void Character::RestorePower()
{
    this->energy = 100;
    std::cout << this->name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->pv -= damage;

    if (this->pv > 0) {
        std::cout << this->name << " takes " << damage << " damage" << std::endl;
    } else {
        std::cout << this->name << " out of combat" << std::endl;
    }
}