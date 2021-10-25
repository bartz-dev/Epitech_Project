/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** cpu.cpp
*/

#include "MyGKrellM.hpp"

enum CPUStates
{
	S_USER = 0,
	S_NICE,
	S_SYSTEM,
	S_IDLE,
	S_IOWAIT,
	S_IRQ,
	S_SOFTIRQ,
	S_STEAL,
	S_GUEST,
	S_GUEST_NICE
};

void ReadCPUStats(std::vector<CPU_Info> &entry)
{
    std::ifstream filestat("/proc/stat");
    std::string actual_line;
    const std::string to_find("cpu");
    const std::size_t len_to_find = to_find.size();

    while (std::getline(filestat, actual_line)) {
        //here line contain CPU State
        if (!actual_line.compare(0, len_to_find, to_find)) {
            std::istringstream res (actual_line);

            //store
            entry.emplace_back(CPU_Info());
            CPU_Info &ent = entry.back();

            //read
            res >> ent.cpu;

            if (ent.cpu.size() > len_to_find)
                ent.cpu.erase(0, len_to_find);
            else
                ent.cpu = "totale:";

            for (int i = 0; i < 10; i++)
                res >> ent.times[i];
        }
    }
}

size_t GetIdleTime(const CPU_Info &e)
{
	return	e.times[S_IDLE] +
			e.times[S_IOWAIT];
}

size_t GetActiveTime(const CPU_Info &e)
{
	return	e.times[S_USER] +
			e.times[S_NICE] +
			e.times[S_SYSTEM] +
			e.times[S_IRQ] +
			e.times[S_SOFTIRQ] +
			e.times[S_STEAL] +
			e.times[S_GUEST] +
			e.times[S_GUEST_NICE];
}

void PrintStats(const std::vector<CPU_Info> & entries1, const std::vector<CPU_Info> & entries2)
{
	const size_t NUM_ENTRIES = entries1.size();

	for(size_t i = 0; i < NUM_ENTRIES; ++i)
	{
		const CPU_Info & e1 = entries1[i];
		const CPU_Info & e2 = entries2[i];

		std::cout.width(3);
		std::cout << e1.cpu << "] ";

		const float ACTIVE_TIME	= static_cast<float>(GetActiveTime(e2) - GetActiveTime(e1));
		const float IDLE_TIME	= static_cast<float>(GetIdleTime(e2) - GetIdleTime(e1));
		const float TOTAL_TIME	= ACTIVE_TIME + IDLE_TIME;

		std::cout << "active: ";
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		std::cout.width(6);
		std::cout.precision(2);
		std::cout << (100.f * ACTIVE_TIME / TOTAL_TIME) << "%";

		std::cout << " - idle: ";
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		std::cout.width(6);
		std::cout.precision(2);
		std::cout << (100.f * IDLE_TIME / TOTAL_TIME) << "%" << std::endl;
	}
}

std::string getCPUName()
{
    char text[255];
    std::string result;
    FILE *name;
    name = popen("cat /proc/cpuinfo | sed -n \"s/^model name[  \\t]*:[ \\t]*//p\" | uniq", "r");
    fgets(text, sizeof(text), name);
    pclose(name);
    result.assign(text);
    result.erase(result.find('\n'), 1);
    return result;
}

float initCpu(std::vector<CPU_Info> &entry1, std::vector<CPU_Info> &entry2)
{
    float ACTIVE_TIME = static_cast<float>(GetActiveTime(entry2[0]) - GetActiveTime(entry1[0]));
	float IDLE_TIME	= static_cast<float>(GetIdleTime(entry2[0]) - GetIdleTime(entry1[0]));
    float TOTAL_TIME = ACTIVE_TIME + IDLE_TIME;
    float result = (100.f * ACTIVE_TIME / TOTAL_TIME);

    return result;
}
