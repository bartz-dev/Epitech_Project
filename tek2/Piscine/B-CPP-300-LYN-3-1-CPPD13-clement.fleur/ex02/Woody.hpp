/*
** EPITECH PROJECT, 2021
** woody
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy
{
    public:
        Woody(const Woody &woody);
        Woody(const std::string &name, const std::string &file = "./woody.txt");
        virtual ~Woody();

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
