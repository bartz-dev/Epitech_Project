/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** meminfo.cpp
*/

#include "MyGKrellM.hpp"
#include <sys/sysinfo.h>

int GKrellm::update_meminfo()
{
    return sysinfo(&this->_meminfo);
}