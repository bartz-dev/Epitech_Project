/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** register
*/

#include "Operand.hpp"
#include "Register.hpp"
#include "Exception.hpp"
#include <iostream>
#include <map>

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
Register<Key, Value>::Register(const size_t membmax)
{
    _membmax = membmax;
    _locked_size = true;
}

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
Register<Key, Value>::Register()
{
    _membmax = 0;
    _locked_size = false;
}

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
Register<Key, Value>::~Register()
{

}

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
bool Register<Key, Value>::setSize(const size_t membmax)
{
    if (!_locked_size) 
    {
        _membmax = membmax;
        return _locked_size = true;
    }
    return false;
}

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
Value Register<Key, Value>::getValueAt(int const rhs) const
{
    size_t index = 0;

    if (rhs < 0)
        throw Exception("negative range");
    index = rhs;
    if (index <= _membmax - 1)
        if (_reg.contains(index) && _reg.at(index) != nullptr)
            return std::move(_reg.at(index));
    throw Exception("no member found");
}

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
size_t Register<Key, Value>::getSize() const
{
    return _membmax;
}

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
bool Register<Key, Value>::push(int const idx, std::shared_ptr<IOperand const> rhs)
{
    size_t index = 0;

    if (idx < 0)
        throw Exception("negative range");
    index = idx;
    if (index <= _membmax - 1)
    {
        _reg[index] = std::move(rhs);
        return true;
    }
    throw Exception("out of boundaries");
}

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_move_assignable_v<Value>
void Register<Key, Value>::clear()
{
    _reg.clear();
}