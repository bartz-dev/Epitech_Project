/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** parser
*/

#include "parser.hpp"
#include "Exception.hpp"
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>

parser::parser(): exited(0)
{
}

parser::~parser()
{
}

void parser::find_flag(std::string elem)
{
    int checker = 0;
    auto z = elem.find('.');
    auto n = elem.find('-');
    int negative = std::count(elem.begin(), elem.end(), '-');

    if (n != std::string::npos && elem[n - 1] != '(')
      throw Exception("Error you can't put number before negative");
    
    if ((n > z && elem.find('-') != std::string::npos) || negative > 1)
        throw Exception("Error negative value must be before separator");
    std::string_view vs(elem);
    if (vs.starts_with("int")) {
        parse_int(elem);
        checker++;
    }
    if (vs.starts_with("float(") || vs.starts_with("double(") || vs.starts_with("bigdecimal(")) {
        parse_float(elem);
        checker++;
    }
    if (checker > 1 || checker == 0)
        throw Exception("Error input type");
}

std::string parser::sort_argument(std::string &elem)
{
    elem.erase(remove_if(elem.begin(), elem.end(), isspace), elem.end());
    return elem;
}

void parser::find_instruction(std::vector<std::pair<std::string, std::string>> &command)
{
    bool checked = 0;

    std::string instr[] =  {"push", "assert", "load", "store", "pop", "dump", "clear", "dup", "swap", "add",
     "sub", "mul", "div", "mod", "print", "exit", "nullptr"};

    for (std::size_t i = 0; instr[i].compare("nullptr") != 0; i++) {
        checked = false;
        if (command.back().first.compare(instr[i]) == 0) {
            checked = 1;
            if (i <= 3)
                find_flag(command.back().second);
            else if (command.back().second.compare(""))
                    throw Exception("arguments forbidden");
            break;
        }
    }
    if (checked == 0)
        throw Exception("Error wrong instruction name!");
}

std::string parser::remove_space(std::string elem)
{
    if (elem[0] == ';')
        return "";
    int i = elem.length() - 1;
    while (elem[i] == ' ')
        elem.erase(i, elem.length());
    for (int j = 0; elem[j] == ' '; j++) {
        elem.erase(0, j);
	    j = 0;
    }
    if (elem[0] == ' ')
      elem.erase(0, 1);
    
    return elem;
}

std::string parser::remove_comment(std::string elem)
{
    if (elem.find(';') != std::string::npos) {
        elem.erase(elem.find(';'), elem.length());
    }
    elem = remove_space(elem);
    return elem;
}

std::vector<std::pair<std::string, std::string> > parser::getData(std::string filepath)
{
    int i = 0;
    std::ifstream file;
    file.open(filepath);
    std::pair<std::string, std::string> tmp;
    std::string cmdline;
    std::string empty = "";

    for (; std::getline(file, cmdline); i++) {
        cmdline = remove_comment(cmdline);
	    if (!cmdline.empty()) {
	        tmp.first = cmdline.substr(0, cmdline.find(' '));
            if ((cmdline.substr(cmdline.find(' ') + 1).length() > 0)) {
                tmp.second = cmdline.substr(cmdline.find(' ') + 1);
                tmp.second = sort_argument(tmp.second.compare(tmp.first) == 0 ? empty : tmp.second);
            }
            command.push_back(tmp);
            find_instruction(command);
        }
    }
    file.close();
    if (command.size() && command.back().first.compare("exit"))
        throw Exception("Instruction after exit!");
    return command;
}

std::vector<std::pair<std::string, std::string> > parser::getData()
{
    std::string cmdline;
    int i = 0;
    std::pair<std::string, std::string> tmp;
    std::string empty = "";

    for (std::string cmdline; std::getline(std::cin, cmdline); i++) {
        if (!cmdline.compare(";;"))
            break;
        cmdline = remove_comment(cmdline);
	    if (!cmdline.empty()) {
	        tmp.first = cmdline.substr(0, cmdline.find(' '));
                if ((cmdline.substr(cmdline.find(' ') + 1).length() > 0)) {
                    tmp.second = cmdline.substr(cmdline.find(' ') + 1);
                    tmp.second = sort_argument(tmp.second.compare(tmp.first) == 0 ? empty : tmp.second);
                }
            command.push_back(tmp);
            find_instruction(command);
        }
    }
    if (command.size() && command.back().first.compare("exit"))
        throw Exception("Instruction after exit!");
    return command;
}
