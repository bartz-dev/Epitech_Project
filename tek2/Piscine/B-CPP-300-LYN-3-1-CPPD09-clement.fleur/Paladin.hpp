/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Paladin.hpp
*/

#ifndef PALADIN_D
#define PALADIN_D

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest
{
    public:
        explicit Paladin(const std::string &name, int level);
};

#endif // !PALADIN_D