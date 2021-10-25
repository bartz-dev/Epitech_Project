/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** ncurses_display.cpp
*/

#include "MyGKrellM.hpp"
#include "ncurses.hpp"
#include <ctime>
#include <cstring>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sstream>

void display_ncurses::display_cpuinfo(module_ncurses &m) const
{
    std::string temperature = this->_infos.getCPUinfo();
    std::string tmp;
    std::istringstream t(temperature);
    std::vector<std::string> vec;

    mvwprintw(m._win, 2, 3, "Cpu Name : %s", this->_infos.getNameCPU().c_str());
    mvwprintw(m._win, 3, 3, "Core     : %s", this->_infos.getCPUcore().c_str());
    mvwprintw(m._win, 4, 3, "Threads  : %d", this->_infos.getCPUthread());
    mvwprintw(m._win, 5, 3, "Usage    : %0.3f %%", this->_infos.getAccurateCPU());
    while (std::getline(t, tmp))
        vec.push_back(tmp);
    for (unsigned int j = 0; j < vec.size(); ++j)
        mvwprintw(m._win, j + 7, 3, "%s", vec[j].replace(vec[j].length() - 19, 19, "\0").append(")").c_str());
}

void display_ncurses::display_meminfo(module_ncurses &m) const
{
    struct sysinfo info = this->_infos.getMem();
    double divide = 1000000.0;
    double totalram = (double)info.totalram / divide;
    double usedram = (double)(info.totalram - info.freeram) / divide;
    double freeram = (double)info.freeram / divide;
    double swapram = (double)(info.totalswap - info.freeswap) / divide;

    mvwprintw(m._win, 2, 3, "Total : %0.3lf MB", totalram);
    mvwprintw(m._win, 3, 3, "Used  : %0.3lf MB", usedram);
    mvwprintw(m._win, 4, 3, "Free  : %0.3lf MB", freeram);
    mvwprintw(m._win, 5, 3, "Swap  : %0.3lf MB", swapram);
}

void display_ncurses::display_network(module_ncurses &m) const
{
    GKrellm a;
    a.update_info();
    a.getNetwork();
    std::string tmp;
    mvwprintw(m._win, 2, 3, "|Receive |Transmit |Bytes Packets |Bytes Packets");
    for (unsigned int i = 0; i < a.nameI.size(); ++i) {
        tmp = a.nameI[i] + "\t";
        if (i == 0)
            tmp += "\t";
        tmp += a.bytes_R[i] + " " + a.packets_R[i] + " ";
        tmp += a.bytes_T[i] + " " + a.packets_T[i];
        mvwprintw(m._win, i + 3, 3, "%s", tmp.c_str());
    }
}

void display_ncurses::display_other(module_ncurses &m) const
{
    struct sysinfo info = this->_infos.getMem();
    int days = info.uptime / 86400;
    int hours = (info.uptime / 3600) - (days * 24);
    int mins = (info.uptime / 60) - (days * 1440) - (hours * 60);
    char str[25] = {0};
    struct utsname osinfo = this->_infos.getOsInfo();

    strncpy(str, this->_infos.getTime().c_str(), 24);
    str[m._x - 12] = 0;
    mvwprintw(m._win, 2, 3, "Date     : %s", str);
    mvwprintw(m._win, 3, 3, "Uptime   : %d days, %d hours, %d min", days, hours, mins);
    mvwprintw(m._win, 4, 3, "Kernel   : %s", osinfo.sysname);
    mvwprintw(m._win, 5, 3, "Release  : %s", osinfo.release);
    mvwprintw(m._win, 6, 3, "Version  : %s", osinfo.version);
    mvwprintw(m._win, 7, 3, "Machine  : %s", osinfo.machine);
    mvwprintw(m._win, 8, 3, "Hostname : %s", this->_infos.getHostname().c_str());
    mvwprintw(m._win, 9, 3, "Username : %s", this->_infos.getUsername().c_str());
}
