/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <map>
#include <fstream>
#include <vector>

class parser
{
private:
    std::vector<std::pair<std::string, std::string> >command;
    bool exited;
public:
    parser();
    ~parser();

    std::vector<std::pair<std::string, std::string> > getData(std::string filepath);
    std::vector<std::pair<std::string, std::string> > getData();
    std::string sort_argument(std::string &elem);
    void find_instruction(std::vector<std::pair<std::string, std::string>> &command);
    void find_flag(std::string elem);
    std::string remove_comment(std::string elem);
    std::string remove_space(std::string elem);

    // number parse
    void parse_int(std::string &elem);
    void parse_float(std::string &elem);
};

#endif /* !PARSER_HPP_ */
