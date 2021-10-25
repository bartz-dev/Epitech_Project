/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** KoalaDoctor.hpp
*/

#include "SickKoala.hpp"

#ifndef DOCTOR_D
#define DOCTOR_D

class KoalaDoctor
{
    private:
        std::string name;
        bool work;
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        void diagnose(SickKoala *koala);
        void timeCheck();
};

#endif // !DOCTOR_D