/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-clement.fleur
** File description:
** Federation.hpp
*/

#include <string>
#include <iostream>
#include "WarpSystem.hpp"

#ifndef FEDERATION_H
#define FEDERATION_H

namespace Federation
{
    class Ship
    {
        int _length;
        int _width;
        std::string _name;
        WarpSystem::Core *core;

        public:
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
    };

    namespace Starfleet
    {
         class Captain
        {
            std::string _name; // provided
            int _age; // not provided during construction

            public:
                Captain(std::string name);
                std::string getName();
                int getAge();
                void setAge(int new_age);
        };
        class Ship
        {
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *core;
            Captain *captain;

            public:
                Ship(int length, int width, std::string name, short maxWarp);
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);
        };
        class Ensign
        {
            std::string _name;

            public:
                explicit Ensign(std::string name);
        };
    }
}

#endif // !FEDERATION_H