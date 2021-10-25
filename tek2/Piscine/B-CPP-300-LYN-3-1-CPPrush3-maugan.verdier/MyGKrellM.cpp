/*
** EPITECH PROJECT, 2020
** MyGKrellM.cpp
** File description:
** MyGKrellM.hpp
*/

#include "MyGKrellM.hpp"
#include <thread>
#include <chrono>
#include <string>
#include <sstream>

GKrellm::GKrellm()
{
}

GKrellm::~GKrellm()
{
}

void GKrellm::update_info()
{
    std::vector<::CPU_Info> entries1;
	std::vector<::CPU_Info> entries2;

    ReadCPUStats(entries1);
    this->update_kernel();
    this->update_hostname();
    this->update_meminfo();
    this->update_datetime();
    this->update_username();

    //temporisation de 1 seconde pour un second relevé du proco
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
    ReadCPUStats(entries2);
    this->setCPU(initCpu(entries1, entries2));
}

std::string GKrellm::getHostname() const
{
    return this->_hostname;
}

std::string GKrellm::getUsername() const
{
    return this->_username;
}

std::string GKrellm::getTime() const
{
    std::ostringstream tmp;

    tmp << std::ctime(&this->_time);
    return tmp.str();
}

struct sysinfo GKrellm::getMem() const
{
    return this->_meminfo;
}

struct utsname GKrellm::getOsInfo() const
{
    return this->_osinfo;
}
