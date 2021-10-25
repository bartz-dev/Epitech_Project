/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** AEnemy.cpp
*/

#include "AEnemy.hpp"
#include <string>
#include <iostream>

AEnemy::AEnemy(int hp, const std::string &type)
{
    this->type = new std::string(type);
    this->hp = hp;
}

void AEnemy::takeDamage(int damage)
{
    if (damage > 0)
        this->hp -= damage;
}

AEnemy::~AEnemy()
{

}

int AEnemy::getHP() const
{
    return this->hp;
}

std::string &AEnemy::getType() const
{
    return *this->type;
}