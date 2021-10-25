/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** main
*/

#include "Vm.hpp"
#include "Exception.hpp"
#include <iostream>
#include "parser.hpp"

int main(int ac, char **argv) try
{
    Vm vm;
    vm.run(ac, argv);
    return 0;
}
catch(const Exception &e)
{
    std::cerr << e.what() << std::endl;
    return 84;
}
catch(const std::exception &e)
{
    std::cerr << e.what() << std::endl;
    return 84;
}
catch(...)
{
    std::cerr << "Unknown exception" << std::endl;
    return 84;
}
