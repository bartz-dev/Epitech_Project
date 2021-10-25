/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-clement.fleur
** File description:
** Borg.hpp
*/

#include "WarpSystem.hpp"
#include <string>
#include <iostream>

#ifndef BORG_D
#define BORG_D

namespace Borg
{
    class Ship
    {
        int _side;
        short _maxWarp;
        WarpSystem::Core *core;

        public:
            Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
    };
}

#endif // !BORG_D
