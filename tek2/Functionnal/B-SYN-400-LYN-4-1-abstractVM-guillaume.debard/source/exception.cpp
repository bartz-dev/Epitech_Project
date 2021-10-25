/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** exception
*/

#include "Exception.hpp"

Exception::Exception(std::string const &rhs)
{
    _error = rhs;
}

Exception::~Exception()
{

}

const char *Exception::what() const noexcept
{
    return _error.c_str();
}