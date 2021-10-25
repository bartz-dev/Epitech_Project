/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** Priest.hpp
*/

#ifndef PRIEST_D
#define PRIEST_D

#include <string>
#include "Mage.hpp"

class Priest : public Mage
{
    public:
        Priest(const std::string &name, int level);


        void RestorePower();
        void Heal();
        int CloseAttack();
        int RangeAttack();
};

#endif // !PRIEST_D