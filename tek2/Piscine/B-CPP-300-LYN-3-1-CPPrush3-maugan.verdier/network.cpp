/*
** EPITECH PROJECT, 2021
** network.cpp
** File description:
** Network
*/

#include "MyGKrellM.hpp"

void GKrellm::get_transmet(std::string line, int c)
{
    int i = 0;
    std::string nbr_b;
    std::string nbr_p;

    while (i < 6) {
        for (; line[c] == ' '; c++);
        for (; line[c] != ' '; c++);
        i++;
    }
    for (;line[c] == ' '; c++);
    for (;line[c] != ' '; c++)
        nbr_b += line[c];
    bytes_T.push_back(nbr_b);
    for (;line[c] == ' '; c++);
    for (;line[c] != ' '; c++)
        nbr_p += line[c];
    packets_T.push_back(nbr_p);
}

void GKrellm::get_receive(std::string line)
{
    std::string name;
    std::string nbr_b;
    std::string nbr_p;

    int c = 0;
    for (; line[c] == ' '; c++);
    for (; line[c] != ' '; c++)
        name += line[c];
    nameI.push_back(name);
    for (;line[c] == ' '; c++);
    for (;line[c] != ' '; c++)
        nbr_b += line[c];
    bytes_R.push_back(nbr_b);
    for (;line[c] == ' '; c++);
    for (;line[c] != ' '; c++)
        nbr_p += line[c];
    packets_R.push_back(nbr_p);
    //std::cout << nameI[0];
    get_transmet(line, c);
}

void GKrellm::getNetwork()
{
    int i = 0;
    std::string line;
    std::ifstream file("/proc/net/dev", std::ios::in);

    while (std::getline(file, line)) {
        if (i > 1) {
            get_receive(line);
        }
        i++;
    }
}
