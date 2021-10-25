/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** main2
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
    LittlePony o("Pony");
    Box box("Boite");
    GiftPaper giftpaper("Papier");

    std::cout << "Elf pick up " << o.getTitle() << std::endl;
    //o.isTaken();

    giftpaper.wrapMeThat(o, box) ;
    std::cout << giftpaper.getBox() << std::endl;
}