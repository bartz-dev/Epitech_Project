/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** vm
*/

#include "Register.hpp"
#include "Factory.hpp"
#include "Utils.hpp"
#include "parser.hpp"
#include "Vm.hpp"
#include "Exception.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <variant>
#include <regex>
#include <algorithm>

using var_t = std::variant<int const, std::unique_ptr<IOperand const>, std::monostate>;

const static std::map<std::string, eOperandType> types = {
    {"int8", INT8},
    {"int16", INT16},
    {"int32", INT32},
    {"float", FLOAT},
    {"double", DOUBLE},
    {"bigdecimal", BIGDECIMAL}
};

Vm::Vm()
{
    _reg.setSize(16);
    _functions["push"] = &Vm::push;
    _functions["pop"] = &Vm::pop;
    _functions["clear"] = &Vm::clear;
    _functions["dup"] = &Vm::dup;
    _functions["swap"] = &Vm::swap;
    _functions["dump"] = &Vm::dump;
    _functions["assert"] = &Vm::assert;
    _functions["add"] = &Vm::add;
    _functions["sub"] = &Vm::sub;
    _functions["mul"] = &Vm::mul;
    _functions["div"] = &Vm::div;
    _functions["mod"] = &Vm::mod;
    _functions["load"] = &Vm::load;
    _functions["store"] = &Vm::store;
    _functions["print"] = &Vm::print;
    _functions["exit"] = &Vm::exit;
}

Vm::~Vm()
{

}

void Vm::push(var_t v)
{
    var_t &ref = v;
    _stack.emplace_front(std::move(std::get<std::unique_ptr<IOperand const>>(ref)));
}

void Vm::pop([[maybe_unused]]var_t)
{
    if (_stack.empty())
        throw Exception("stack empty");
    _stack.pop_front();
}

void Vm::clear([[maybe_unused]]var_t)
{
    _stack.clear();
}

void Vm::dup([[maybe_unused]]var_t)
{
    if (!_stack.empty())
    {
        auto top = _stack.front();
        _stack.emplace_front(top);
    }
}

void Vm::swap([[maybe_unused]]var_t)
{
    if (!_stack.empty())
    {
        auto top = _stack.front();
        _stack.pop_front();
        auto bot = _stack.front();
        _stack.pop_front();
        _stack.emplace_front(top);
        _stack.emplace_front(bot);
        //_stack.pop_front();
        //_stack.pop_back();
        //_stack.emplace_front(bot);
        //_stack.emplace_back(top);
    }
}   

void Vm::dump([[maybe_unused]]var_t)
{
    if (!_stack.empty())
    {
        for (auto op : _stack) 
        {
            switch (op->getType())
            {
                case FLOAT: std::cout.precision(7);
                    break;
                case DOUBLE: std::cout.precision(15);
                    break;
                case BIGDECIMAL: std::cout.precision(200);
                    break;
                default: std::cout.precision(6);
                    break;
            }
            std::cout << std::stod(op->toString()) << std::endl;
        }
    }
}

void Vm::assert(var_t v)
{
    if (!_stack.empty())
    {
        var_t &ref = v;
        auto top = _stack.front();
        if (*std::get<std::unique_ptr<IOperand const>>(ref) != *top)
            throw Exception("assert failed");
        return;
    }
    throw Exception("assert failed");
}

void Vm::add([[maybe_unused]]var_t)
{
    if (!_stack.empty() && _stack.size() >= 2)
    {
        auto a = _stack.front();
        _stack.pop_front();
        auto b = _stack.front();
        _stack.pop_front();

        //_stack.emplace_front(*a + *b); was wrong
        _stack.emplace_front(*b + *a);
        return;
    }
    throw Exception("not enough members");
}

void Vm::sub([[maybe_unused]]var_t)
{
    if (!_stack.empty() && _stack.size() >= 2)
    {
        auto a = _stack.front();
        _stack.pop_front();
        auto b = _stack.front();
        _stack.pop_front();

        //_stack.emplace_front(*a - *b);
        _stack.emplace_front(*b - *a);
        return;
    }
    throw Exception("not enough members");
}

void Vm::mul([[maybe_unused]]var_t)
{
    if (!_stack.empty() && _stack.size() >= 2)
    {
        auto a = _stack.front();
        _stack.pop_front();
        auto b = _stack.front();
        _stack.pop_front();

        //_stack.emplace_front(*a * *b);
        _stack.emplace_front(*b * *a);
        return;
    }
    throw Exception("not enough members");
}

void Vm::div([[maybe_unused]]var_t)
{
    if (!_stack.empty() && _stack.size() >= 2)
    {
        auto a = _stack.front();
        _stack.pop_front();
        auto b = _stack.front();
        _stack.pop_front();

        //if (std::stod(b->toString()) == 0)
        if (std::stod(a->toString()) == 0)
            exit(), throw Exception("wrong range");
        //_stack.emplace_front(*a / *b);
        _stack.emplace_front(*b / *a);
        return;
    }
    throw Exception("not enough members");
}

void Vm::mod([[maybe_unused]]var_t)
{
    if (!_stack.empty() && _stack.size() >= 2)
    {
        auto a = _stack.front();
        _stack.pop_front();
        auto b = _stack.front();
        _stack.pop_front();
        //_stack.emplace_front(*a % *b);
        _stack.emplace_front(*b % *a);
        return;
    }
    throw Exception("not enough members");
}

void Vm::load(var_t v)
{
    var_t &ref = v;
    auto index = std::stoi(std::get<std::unique_ptr<IOperand const>>(ref)->toString());
    auto reg = _reg.getValueAt(index);

    _stack.emplace_front(reg);
}

void Vm::store(var_t v)
{
    if (!_stack.empty())
    {
        var_t &ref = v;
        auto value = _stack.front();
        auto index = std::stoi(std::get<std::unique_ptr<IOperand const>>(ref)->toString());
        _reg.push(index, value);
        _stack.pop_front();
    }
}

void Vm::print([[maybe_unused]]var_t)
{
    if (!_stack.empty())
    {
        auto v = _stack.front();

        if (v->getType() != INT8)
        {
            exit();
            throw Exception("top not an INT8");
        }
        char p = std::stoi(v->toString());
        std::cout << p << std::endl;
    }
}

void Vm::exit([[maybe_unused]]var_t)
{
    _reg.clear();
    clear();
}

var_t Vm::processToken(std::string const &rhs)
{
    std::string tocheck = rhs;
    std::vector<std::string> words = {"int8", "int16", "int32", "float", "double", "bigdecimal"};
    trim(tocheck);
    Factory fact;

    for (auto word : words)
    {
        if (auto n = tocheck.find(word) != std::string::npos)
        {
            auto value = std::regex_replace(tocheck, std::regex("^(.*?)([1-9][0-9]*)?\\((-?[0-9]*(\\.[0-9]*)?)\\)$"), std::string("$3"));
            auto jaj = tocheck.erase(tocheck.substr(n).find('(') + 1);

            return fact.createOperand(types.at(jaj), value);
        }
    }
    if (!tocheck.compare(""))
        return 0;
    return std::stoi(tocheck);
}

void Vm::run(int ac, char **av)
{
    parser parse;
    if (ac == 2 && check_file(av[1]) == 1) 
        _instructions = parse.getData(av[1]);
    else if (ac == 1)
        _instructions = parse.getData();

    for (auto &set : _instructions)
    {
        if (_functions.contains(set.first))
        {
            (this->*this->_functions[set.first])(processToken(set.second));
        } else
            throw Exception("unknown function");
    }
}