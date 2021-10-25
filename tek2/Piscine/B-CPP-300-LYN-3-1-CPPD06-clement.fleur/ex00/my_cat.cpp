/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** my_cat.cpp
*/

#include <iostream>
#include <string>
#include <fstream>

void m_cat(char **av)
{
    int i = 1;
    char c;

    while (av[i]) {
        std::ifstream file (av[i], std::ios::in);
        if (!file) {
            std::cerr << "my_cat: " <<  av[i] << ": No such file or directory"
             << std::endl;
        } else {
            while (file.get(c))
                std::cout << c;
        }
        i++;
    }
}


int main(int ac, char **av)
{
    if (ac < 2)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    m_cat(av);

    return 0;
}