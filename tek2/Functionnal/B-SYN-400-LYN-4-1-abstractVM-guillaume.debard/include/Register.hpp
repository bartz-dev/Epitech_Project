/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** Register
*/

#pragma once

#include "Operand.hpp"
#include <vector>
#include <map>

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
class Register
{
    public:
        Register();
        Register(const size_t membmax);
        ~Register();
        bool setSize(const size_t membmax);
        Value getValueAt(int const) const;
        size_t getSize() const;
        bool push(int const, std::shared_ptr<IOperand const>);
        void clear();
    private:
        std::map<Key, Value> _reg;
        size_t _membmax;
        bool _locked_size;
};

template class Register<int, std::shared_ptr<IOperand const>>;