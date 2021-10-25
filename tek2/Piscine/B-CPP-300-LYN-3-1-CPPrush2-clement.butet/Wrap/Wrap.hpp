/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Wrap
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "../Objects/Object.hpp"
#include <fstream>
#include "../Wrap/GiftPaper.hpp"
#include "../Objects/Teddy.hpp"

#ifndef WRAP_HPP_
#define WRAP_HPP_

class Wrap : public Object
{
    public:
        Wrap(const std::string &name);
        ~Wrap();
        Wrap &wrapMeThat(const Object &_Toy, const Object &Gift_Paper);
        Wrap &operator = (Object *object);
        Object *getObject();
        void setIsOpen(int isOpen);
        const std::string getToy();
        const std::string getBox();


    protected:
        Object *object;
        bool _isopen;
        std::string toy;
        std::string box;
    private:
};

#endif /* !WRAP_HPP_ */
