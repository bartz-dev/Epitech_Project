/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Charactere.hpp
*/

#ifndef FAMILY_MATTERS_D
#define FAMILY_MATTERS_D

#include <string>
#include <iostream>

class Character
{
    protected:
        std::string name;
        int level;
        int pv;
        int energy;

        int strength;
        int stamina;
        int intelligence;
        int spirit;
        int agility;

    public:
        //init
        explicit Character(const std::string &name, int level);
        const std::string &getName() const;

        //getter
        int getLvl() const;
        int getPv() const;
        int getPower() const;

        //combat
        int CloseAttack();
        void Heal();
        int RangeAttack();
        void RestorePower();
        void TakeDamage(int damage);

        typedef enum AttackRange {
        CLOSE,
        RANGE
        } AttackRange;
        AttackRange Range;
};

#endif // !FAMILY_MATTERS_D