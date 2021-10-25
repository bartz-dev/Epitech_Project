/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** main.cpp
*/

#include "MyGKrellM.hpp"
#include "ncurses.hpp"

int ncurses_primary_window(GKrellm &a)
{
    display_ncurses window(a);
    return 0;
}

int main(int ac, char **argv)
{
    GKrellm a;
    std::string graph = "-g";
    std::string term = "-t";

    if (ac != 2)
        return 0;
    if (argv[1] == graph)
        graphique();
    else if (argv[1] == term)
        ncurses_primary_window(a);
    return 0;
}
