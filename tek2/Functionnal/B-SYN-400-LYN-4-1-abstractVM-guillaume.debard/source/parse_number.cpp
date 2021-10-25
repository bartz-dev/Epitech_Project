/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** pars_number
*/

#include "parser.hpp"
#include "Exception.hpp"

void parser::parse_int(std::string &elem)
{
    std::string tmp;
    int index = 1;
    
    if (elem.find("int8(") == std::string::npos && elem.find("int16(") == std::string::npos && elem.find("int32(") == std::string::npos)
        throw Exception("Wrong int type!");
    tmp = elem.substr(elem.find('('), elem.find(')'));
    if (tmp.find(' ') != std::string::npos)
        throw Exception("Error space between argument");
    if (tmp.find(',') == tmp.npos) {
        while (tmp[index] != ')') {
            if (isdigit(tmp[index]) == 0 && tmp[index] != '-')
                throw Exception("error int");
            index++;
        }
    }
    else
        throw Exception("character except");
}

void parser::parse_float(std::string &elem)
{
    std::string tmp;
    int index = 1;
    int point = 0;

    if (elem.find(',') != std::string::npos)
        throw Exception("Error american value are denied");
    tmp = elem.substr(elem.find('('), elem.find(')'));
    if (tmp.find(' ') != std::string::npos)
        throw Exception("Error space between argument");
    if (tmp.find(',') == tmp.npos) {
        while (tmp[index] != ')') {
            if (tmp[index] == '.') {
                point += 1;
                (tmp[index - 1] < 48 || tmp[index - 1] > 57) && tmp[index - 1] != '-' ? throw Exception("error") : index++;
            }
            if ((isdigit(tmp[index]) == 0 && tmp[index] != '-') || point > 1)
                throw Exception("error int");
            index++;
        }
    }
}
