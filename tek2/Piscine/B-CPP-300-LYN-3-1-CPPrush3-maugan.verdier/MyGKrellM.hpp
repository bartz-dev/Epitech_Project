/*
** EPITECH PROJECT, 2020
** MyGKrellM
** File description:
** MyGKrellM.hpp
*/

#ifndef _GKRELLM_H_
#define _GKRELLM_H_

#include <string>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include "processor.hpp"


class GKrellm {
    public:
        GKrellm();
        ~GKrellm();
        void update_kernel();
        int update_hostname();
        int update_meminfo();
        void update_info();
        void update_datetime();
        void update_username();
        void getNetwork();
        void get_transmet(std::string line, int c);
        void get_receive(std::string line);
        void setCPU(float accurate);
        std::string getHostname() const;
        std::string getUsername() const;
        std::string getTime() const;
        struct sysinfo getMem() const;
        struct utsname getOsInfo() const;
        std::string getNameCPU() const;
        float getAccurateCPU() const;
        int getCPUthread() const;
        std::string getCPUcore() const;
        std::string getCPUinfo() const;
        std::vector<std::string> nameI;
        std::vector<std::string> bytes_R;
        std::vector<std::string> packets_R;
        std::vector<std::string> bytes_T;
        std::vector<std::string> packets_T;

    private:
        std::string _CPUname;
        float _CPUaccurate;
        int _CPUthread;
        std::string _CPUcore;
        std::string _CPUcoreInfo;
        struct sysinfo _meminfo;
        struct utsname _osinfo;
        std::string _hostname;
        std::string _username;
        std::time_t _time;
};

int graphique();
std::time_t date_time();

#endif
