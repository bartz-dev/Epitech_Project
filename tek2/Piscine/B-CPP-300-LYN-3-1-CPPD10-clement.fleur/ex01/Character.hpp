/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** Character.hpp
*/

#ifndef CHARACTER_D
#define CHARACTER_D

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character
{
    std::string *name;
    int ap;
    AWeapon *weapon;

    public:
        Character(const std::string &name);
        virtual ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string &getName() const;
        int getAP() const;
        AWeapon *getWeapon() const;


};

std::ostream& operator<<(std::ostream &os, Character const &Character);

#endif // !CHARACTER_D