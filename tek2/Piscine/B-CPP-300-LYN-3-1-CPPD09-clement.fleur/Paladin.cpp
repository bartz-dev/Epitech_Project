/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Paladin.cpp
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level)
{
    this->strength = 6;
}