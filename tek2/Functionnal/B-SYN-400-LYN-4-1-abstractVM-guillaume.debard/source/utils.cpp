/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** utils
*/

#include "Operand.hpp"
#include "Utils.hpp"
#include "Exception.hpp"
#include <limits>
#include <iostream>
#include <fstream>
#include <variant>
#include <typeinfo>

std::string const enumToString(eOperandType const &t)
{
    switch (t)
    {
        case INT8: return "INT8";
        case INT16: return "INT16";
        case INT32: return "INT32";
        case FLOAT: return "FLOAT";
        case DOUBLE: return "DOUBLE";
        case BIGDECIMAL: return "BIGDECIMAL";
        default: throw Exception("unknown enum");
    }
}

long double getEnumMax(eOperandType const &rhs)
{
    switch (rhs)
    {
        case INT8: return std::numeric_limits<int8_t>::max();
        case INT16: return std::numeric_limits<int16_t>::max();
        case INT32: return std::numeric_limits<int32_t>::max();
        case FLOAT: return std::numeric_limits<float>::max();
        case DOUBLE: return std::numeric_limits<double>::max();
        case BIGDECIMAL: return std::numeric_limits<long double>::max();
        default: throw Exception("type unknown");
    };
}

void setEnumPrecision(eOperandType const &rhs, std::ostringstream &ss)
{
    switch (rhs)
    {
        case FLOAT: ss.precision(7);
            break;
        case DOUBLE: ss.precision(15);
            break;
        case BIGDECIMAL: ss.precision(200);
            break;
        default: ss.precision(6);
            break;
    }
}

long double getEnumMin(eOperandType const &rhs)
{
    switch (rhs)
    {
        case INT8: return std::numeric_limits<int8_t>::min();
        case INT16: return std::numeric_limits<int16_t>::min();
        case INT32: return std::numeric_limits<int32_t>::min();
        case FLOAT: return -std::numeric_limits<float>::max();
        case DOUBLE: return -std::numeric_limits<double>::max();
        case BIGDECIMAL: return -std::numeric_limits<long double>::max();
        default: throw Exception("type unknown");
    };
}

int check_file(std::string filepath)
{
    std::string str;
    std::ifstream file;
    file.open(filepath);

    if (!file.is_open())
        throw Exception("error can't open file !");
    if (filepath.find(".avm", filepath.length() - 4) == std::string::npos)
        throw Exception("Error file not recognized!");
    while (std::getline(file, str)) {
        if (str.compare("exit")) 
        {
            file.close();
            return 1;
        }
    }
    file.close();
    return 0;
}