/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** Sorcerer.hpp
*/

#ifndef SORCERER_D
#define SORCERER_D

#include <string>
#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{
    std::string name;
    std::string title;

    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();

        //getter
        std::string getName() const;
        std::string getTitle() const;

        void polymorph(const Victim &victim);
        void polymorph(const Peon &peon);
};

std::ostream& operator<<(std::ostream &os, const Sorcerer &sorcers);

#endif // !SORCERER_D