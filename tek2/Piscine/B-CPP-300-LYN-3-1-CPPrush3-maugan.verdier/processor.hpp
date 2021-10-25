/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** processor
*/

#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

#include "MyGKrellM.hpp"

struct CPU_Info
{
    std::string cpu;
    size_t times[10];
};

void ReadCPUStats(std::vector<CPU_Info> &entry);
void PrintStats(const std::vector<CPU_Info> & entries1, const std::vector<CPU_Info> & entries2);
size_t GetActiveTime(const CPU_Info & e);
size_t GetIdleTime(const CPU_Info & e);
std::string getCPUName();
float initCpu(std::vector<CPU_Info> &entries1, std::vector<CPU_Info> &entries2);
std::string my_getCommand(std::string command);

#endif /* !PROCESSOR_HPP_ */
