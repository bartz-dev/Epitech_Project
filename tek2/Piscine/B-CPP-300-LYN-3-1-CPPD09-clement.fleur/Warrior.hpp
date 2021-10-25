/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Warrior.hpp
*/

#ifndef WARRIOR_D
#define WARRIOR_D

#include "Character.hpp"

class Warrior : virtual public Character
{
    protected:
        std::string weaponName;

    public:
        explicit Warrior(const std::string &name, int level);

        //combat
        int CloseAttack();
        void Heal();
        int RangeAttack();
        void RestorePower();
};

#endif // !WARRIOR_D