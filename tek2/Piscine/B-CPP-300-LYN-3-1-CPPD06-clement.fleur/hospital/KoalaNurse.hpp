/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** KoalaNurse.hpp
*/

#include <string>
#include <iostream>

#ifndef NURSE_D
#define NURSE_D

class KoalaNurse
{
    private:
        int id;
        bool working;

    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *SickKoala);
        std::string readReport(std::string filename);
        void timeCheck();
};

#endif // !NURSE_D