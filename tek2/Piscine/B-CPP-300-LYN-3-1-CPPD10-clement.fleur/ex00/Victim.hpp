/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-clement.fleur
** File description:
** Victim.hpp
*/

#ifndef VICTIM_D
#define VICTIM_D

#include <string>
#include <iostream>

class Victim
{
    protected:
        std::string name;

    public:
        explicit Victim(std::string name);
        ~Victim();

        //getter
        std::string getName() const;
        void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &os, const Victim &victim);

#endif // !VICTIM_D