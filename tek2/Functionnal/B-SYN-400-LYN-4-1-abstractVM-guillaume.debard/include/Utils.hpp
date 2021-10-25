/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** Utils
*/

#pragma once

#include "Operand.hpp"
#include "Exception.hpp"
#include <string>
#include <iostream>
#include <concepts>
#include <variant>
#include <iomanip>

std::string const enumToString(eOperandType const &t);
long double getEnumMax(eOperandType const &rhs);
long double getEnumMin(eOperandType const &rhs);
int check_file(std::string file);
void setEnumPrecision(eOperandType const &rhs, std::ostringstream &ss);

template <IsOperand T>
std::string check_add(IOperand const *a, IOperand const *b);
template <IsOperand T>
std::string check_sub(IOperand const *a, IOperand const *b);
template <IsOperand T>
std::string check_mul(IOperand const *a, IOperand const *b);
template <IsOperand T>
std::string check_div(IOperand const *a, IOperand const *b);
template <IsOperand T>
std::string check_mod(IOperand const *a, IOperand const *b);

template <IsOperand T>
std::string check_add(IOperand const *a, IOperand const *b)
{
    long double const test = std::stold(a->toString()) + std::stold(b->toString());
    auto highest = (a->getType() < b->getType()) ? b->getType() : a->getType();
    std::ostringstream ss;
    
    if (test > getEnumMax(highest))
        throw Exception(enumToString(highest) + " overflow");
    else if (test < getEnumMin(highest))
        throw Exception(enumToString(highest) + " underflow");
    //T result = test;
    setEnumPrecision(highest, ss);
    ss << test;
    return ss.str();
}

template <IsOperand T>
std::string check_sub(IOperand const *a, IOperand const *b)
{
    long double const test = std::stold(a->toString()) - std::stold(b->toString());
    auto highest = (a->getType() < b->getType()) ? b->getType() : a->getType();
    std::ostringstream ss;
    
    if (test > getEnumMax(highest))
        throw Exception(enumToString(highest) + " overflow");
    else if (test < getEnumMin(highest))
        throw Exception(enumToString(highest) + " underflow");
    //T result = test;
    setEnumPrecision(highest, ss);
    ss << test;
    return ss.str();
}

template <IsOperand T>
std::string check_mul(IOperand const *a, IOperand const *b)
{
    long double const test = std::stold(a->toString()) * std::stold(b->toString());
    auto highest = (a->getType() < b->getType()) ? b->getType() : a->getType();
    std::ostringstream ss;

    if (test > getEnumMax(highest))
        throw Exception(enumToString(highest) + " overflow");
    else if (test < getEnumMin(highest))
        throw Exception(enumToString(highest) + " underflow");
    //T result = test;
    setEnumPrecision(highest, ss);
    ss << test;
    return ss.str();
}

template <IsOperand T>
std::string check_div(IOperand const *a, IOperand const *b)
{
    if (std::stold(b->toString()) == 0)
        throw Exception("division by 0");
    long double const test = std::stold(a->toString()) / std::stold(b->toString());
    auto highest = (a->getType() < b->getType()) ? b->getType() : a->getType();
    std::ostringstream ss;
    
    if (test > getEnumMax(highest))
        throw Exception(enumToString(highest) + " overflow");
    else if (test < getEnumMin(highest))
        throw Exception(enumToString(highest) + " underflow");
    setEnumPrecision(highest, ss);
    ss << test;
    return ss.str();
}

template <IsOperand T>
std::string check_mod(IOperand const *a, IOperand const *b)
{
    if (a->getType() > INT32 || b->getType() > INT32 || std::stol(b->toString()) == 0)
        throw Exception("modulo floating");
    int64_t const test = std::stoll(a->toString()) % std::stoll(b->toString());
    auto highest = (a->getType() < b->getType()) ? b->getType() : a->getType();
    std::ostringstream ss;
    
    if (test > getEnumMax(highest))
        throw Exception(enumToString(highest) + " overflow");
    else if (test < getEnumMin(highest))
        throw Exception(enumToString(highest) + " underflow");
    //T result = test;
    setEnumPrecision(highest, ss);
    ss << test;
    return ss.str();
}

static inline void ltrim(std::string &rhs)
{ 
    rhs.erase(rhs.begin(), std::find_if(rhs.begin(), rhs.end(), [](int ch) 
    { return !std::isspace(ch); }));
}

static inline void rtrim(std::string &rhs) 
{
    rhs.erase(std::find_if(rhs.rbegin(), rhs.rend(), [](int ch) 
    { return !std::isspace(ch); }).base(), rhs.end());
}

static inline void trim(std::string &rhs)
{
    ltrim(rhs);
    rtrim(rhs);
}
