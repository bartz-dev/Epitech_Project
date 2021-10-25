/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** Peon.hpp
*/

#ifndef PEON_D
#define PEON_D

#include "Victim.hpp"

class Peon : public Victim
{
    public:
        Peon(std::string name);
        ~Peon();

        void getPolymorphed() const;
        void polymorph(const Peon &peon);
};

#endif // !PEON_D