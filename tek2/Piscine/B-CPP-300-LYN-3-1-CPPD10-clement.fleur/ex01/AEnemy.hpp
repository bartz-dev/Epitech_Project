/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** AEnemy.hpp
*/

#ifndef A_ENEMY_D
#define A_ENEMY_D

#include <string>
#include <iostream>

class AEnemy
{
    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();

        virtual void takeDamage(int damage);

        //getter
        std::string &getType() const;
        int getHP() const;

    private:
        std::string *type;
        int hp;
};

#endif // !A_ENEMY_D