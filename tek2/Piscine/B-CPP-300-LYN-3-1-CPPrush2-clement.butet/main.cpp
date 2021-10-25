/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** main.cpp
*/

#include "Wrap/Box.hpp"
#include "Wrap/GiftPaper.hpp"
#include "Elf/Elf.hpp"
#include "Objects/LittlePony.hpp"
#include "Objects/Teddy.hpp"
#include <string>
#include <iostream>

int main(void)
{
    Teddy o("Ourson");
    Box box("Boite");
    GiftPaper giftpaper("Papier");

    std::cout << "Elf pick up " << o.getTitle() << std::endl;
    //o.isTaken();

    std::cout << o.getTitle() << std::endl;
    giftpaper.setIsOpen(true);
    giftpaper.wrapMeThat(o, box);
    std::cout << giftpaper.getBox() << std::endl;
}