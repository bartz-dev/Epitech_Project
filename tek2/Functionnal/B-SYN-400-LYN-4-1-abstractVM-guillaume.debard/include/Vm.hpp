/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** vm
*/

#pragma once

#include "Operand.hpp"
#include "Register.hpp"
#include <deque>
#include <variant>
#include <functional>
#include <map>

class Vm
{
    using var_t = std::variant<int const, std::unique_ptr<IOperand const>, std::monostate>;
    using Func = void (Vm::*)(Vm::var_t);

    std::map<std::string, Func> _functions;
    std::deque<std::shared_ptr<IOperand const>> _stack;
    Register<int, std::shared_ptr<IOperand const>> _reg;
    std::vector<std::pair<std::string, std::string>> _instructions;

    void push(var_t);
    void pop(var_t = 0);
    void clear(var_t = 0);
    void dup(var_t = 0);
    void swap(var_t = 0);
    void dump(var_t = 0);
    void assert(var_t);
    void add(var_t = 0);
    void sub(var_t = 0);
    void mul(var_t = 0);
    void div(var_t = 0);
    void mod(var_t = 0);
    void load(var_t);
    void store(var_t);
    void print(var_t = 0);
    void exit(var_t = 0);
    var_t processToken(std::string const &);
public:
    Vm();
    ~Vm();
    void run(int ac, char**av);
};