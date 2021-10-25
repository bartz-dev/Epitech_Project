/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** my_temp.cpp
*/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

int	main(int ac, char **av)
{
    std::string str;
    float result;
    float temperature;

    std::cin >> temperature >> str;

    if (!strncmp(str.data(), "Celsius", 7)) {
        result = 9.0 / 5.0 * temperature + 32;
        std::cout.precision(3);
        std::cout << std::setw(16) << std::fixed << result << std::setw(16)
        << "Fahrenheit" << std::endl;
    }
    else if (!strncmp(str.data(), "Fahrenheit", 10)) {
        result = 5.0 / 9.0 * (temperature - 32);
        std::cout.precision(3);
        std::cout << std::setw(16) << std::fixed << result << std::setw(16)
        << "Celsius" << std::endl;
    }
    return 0;
}