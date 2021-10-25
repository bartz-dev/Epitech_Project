/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name)
{
    this->name = new std::string(name);
    this->ap = 40;
}

Character::~Character()
{

}

std::string &Character::getName() const
{
    return *this->name;
}

void Character::recoverAP()
{
    this->ap += 10;
    if (this->ap > 40)
        this->ap = 40;
}

void Character::attack(AEnemy *enemy)
{
    if ((this->getWeapon() && this->ap >= this->weapon->getAPCost())) {
        std::cout << this->getName() << " attacks " << enemy->getType()
        << " with a " << this->weapon->getName() << std::endl;
        this->ap -= this->weapon->getAPCost();
        this->weapon->attack();
        enemy->takeDamage(this->weapon->getDamage());
        if (enemy->getHP() <= 0) {
            delete enemy;
            enemy = NULL;
        }
    }
}

int Character::getAP() const
{
    return this->ap;
}

AWeapon *Character::getWeapon() const
{
    if (this->weapon)
        return this->weapon;
    return nullptr;
}



void Character::equip(AWeapon *weapon)
{
    this->weapon = weapon;
}

std::ostream& operator<<(std::ostream &os,  Character const &character)
{
    if (character.getWeapon() == nullptr)
        os << character.getName() << " has " << character.getAP()
        << " AP and is unarmed" << std::endl;
    else
        os << character.getName() << " has " << character.getAP() <<
        " AP and wields a " << character.getWeapon()->getName() << std::endl;
    return os;

}