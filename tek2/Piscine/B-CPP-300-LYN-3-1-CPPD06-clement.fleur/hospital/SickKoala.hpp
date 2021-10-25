/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** SickKoala.hpp
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

#ifndef KOALA_D
#define KOALA_D

class SickKoala
{
    public:
    std::string name;
    SickKoala(std::string name);
    ~SickKoala();

    void poke();
    bool takeDrug(std::string str);
    void overDrive(std::string str);
    std::string getName();
};

#endif // !KOALA_D