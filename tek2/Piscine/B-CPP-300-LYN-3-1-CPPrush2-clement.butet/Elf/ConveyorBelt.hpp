/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** ConveyorBelt
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "../Objects/Object.hpp"

#ifndef CONVEYORBELT_HPP_
#define CONVEYORBELT_HPP_

class IConveyorBelt {
    public:
        IConveyorBelt();
        ~IConveyorBelt();

        IConveyorBelt *createConveyorBelt();
        void PushIN(Object *);
        void PushOUT();
        void putObject(Object *);
        Object *takeObject();

    protected:
        int _onBelt;
        Object *item = NULL;
    private:
};

#endif /* !CONVEYORBELT_HPP_ */
