/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** fluffy.hpp
*/

#ifndef MAGE_D
#define MAGE_D

#include "Warrior.hpp"

class Mage : virtual public Character
{
    public:
        explicit Mage(const std::string &name, int level);

        void RestorePower();
        void Heal();
        int CloseAttack();
        int RangeAttack();
};

#endif // !MAGE_D