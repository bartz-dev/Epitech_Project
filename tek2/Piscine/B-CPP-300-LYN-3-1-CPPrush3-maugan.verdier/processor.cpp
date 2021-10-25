/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** processor.cpp
*/

#include "MyGKrellM.hpp"
#include <thread>
#include <stdlib.h>

void GKrellm::setCPU(float accurate)
{
    this->_CPUname = getCPUName();
    this->_CPUaccurate = accurate;
    this->_CPUthread = std::thread::hardware_concurrency();
    this->_CPUcore = my_getCommand("sensors | egrep \"Core\" | wc -l");
    this->_CPUcoreInfo = my_getCommand("sensors | egrep \"Core\" | tr -s ' '");
}

std::string my_getCommand(std::string command)
{
    char text[1024];
    std::string result;
    FILE *name;
    name = popen(command.data(), "r");
    while (fgets(text, sizeof(text), name))
        result = result + text;
    result.erase(result.size() - 1);
    pclose(name);
    return result;
}

std::string GKrellm::getNameCPU() const
{
    return this->_CPUname;
}

float GKrellm::getAccurateCPU() const
{
    return this->_CPUaccurate;
}

int GKrellm::getCPUthread() const
{
    return this->_CPUthread;
}

std::string GKrellm::getCPUcore() const
{
    return this->_CPUcore;
}

std::string GKrellm::getCPUinfo() const
{
    return this->_CPUcoreInfo;
}