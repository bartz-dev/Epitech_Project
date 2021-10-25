/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** Exception
*/

#pragma once

#include <exception>
#include <string>

class Exception : public std::exception 
{
    std::string _error;
public:
    virtual const char *what() const noexcept;
    Exception(std::string const &);
    virtual ~Exception();
};