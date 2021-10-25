/*
** EPITECH PROJECT, 2021
** buzz
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
        Buzz(Buzz const &buzz);
        Buzz(std::string const &name, std::string const &file = "./buzz.txt");
        ~Buzz();

        void speak(std::string const &data);
};

#endif /* !BUZZ_HPP_ */
