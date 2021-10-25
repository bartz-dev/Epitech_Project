/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** operand
*/

//export module operand;
#include "Operand.hpp"
#include "Utils.hpp"
#include "Factory.hpp"
#include <string>
#include <limits>
#include <iostream>
#include <memory>

//TEMPLATE
template <IsOperand T>
Operand<T>::Operand(eOperandType type, const std::string &value)
{
	this->type = type;
	this->value = value;
}

template <IsOperand T>
Operand<T>::~Operand()
{

}

template <IsOperand T>
std::string const &Operand<T>::toString(void) const
{
	return this->value;
}

template <IsOperand T>
eOperandType Operand<T>::getType(void) const
{
	return this->type;
}

template <IsOperand T>
std::unique_ptr<IOperand const> Operand<T>::operator+(IOperand const &rhs) const
{
    Factory fact;
    auto highest = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
    std::string result = check_add<T>(this, &rhs);
    std::unique_ptr<IOperand const> ret = fact.createOperand(highest, result);
    return ret;
}

template <IsOperand T>
std::unique_ptr<IOperand const> Operand<T>::operator-(IOperand const &rhs) const
{
    Factory fact;
    auto highest = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
    std::string result = check_sub<T>(this, &rhs);
    std::unique_ptr<IOperand const> ret = fact.createOperand(highest, result);
    return ret;
}

template <IsOperand T>
std::unique_ptr<IOperand const> Operand<T>::operator*(IOperand const &rhs) const
{
    Factory fact;
    auto highest = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
    std::string result = check_mul<T>(this, &rhs);
    std::unique_ptr<IOperand const> ret = fact.createOperand(highest, result);
    return ret;
}

template <IsOperand T>
std::unique_ptr<IOperand const> Operand<T>::operator/(IOperand const &rhs) const
{
    Factory fact;
    auto highest = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
    std::string result = check_div<T>(this, &rhs);
    std::unique_ptr<IOperand const> ret = fact.createOperand(highest, result);
    return ret;
}

template <IsOperand T>
std::unique_ptr<IOperand const> Operand<T>::operator%(IOperand const &rhs) const
{
    Factory fact;
    auto highest = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
    std::string result = check_mod<T>(this, &rhs);
    std::unique_ptr<IOperand const> ret = fact.createOperand(highest, result);
    return ret;
}

template <IsOperand T>
std::partial_ordering Operand<T>::operator<=>(IOperand const &rhs) const
{
    auto order = type <=> rhs.getType();

    if (order == std::strong_ordering::less || order == std::strong_ordering::equivalent || order == std::strong_ordering::greater)
        return std::stod(value) <=> std::stod(rhs.toString()); 
    return std::partial_ordering::unordered;
}

template <IsOperand T>
bool Operand<T>::operator==(IOperand const &rhs) const
{
    return std::stod(value) == std::stod(rhs.toString()) && type == rhs.getType();
}

Int8::Int8(std::string const &value): Operand(INT8, value)
{

}

Int16::Int16(std::string const &value): Operand(INT16, value)
{

}


Int32::Int32(std::string const &value): Operand(INT32, value)
{

}

Float::Float(std::string const &value): Operand(FLOAT, value)
{

}

Double::Double(std::string const &value): Operand(DOUBLE, value)
{

}

BigDecimal::BigDecimal(std::string const &value): Operand(BIGDECIMAL, value)
{

}