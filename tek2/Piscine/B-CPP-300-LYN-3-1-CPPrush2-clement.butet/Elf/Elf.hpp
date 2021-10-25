/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Elf
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "../Objects/Object.hpp"

#ifndef ELF_HPP_
#define ELF_HPP_

class Elf {
    public:
        Elf();
        ~Elf();

        void take(Object &object);
        void put(Object &object);

    protected:
        bool _hold;
    private:
};

#endif /* !ELF_HPP_ */
