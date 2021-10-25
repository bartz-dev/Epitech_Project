/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** Factory
*/

#pragma once

#include "Operand.hpp"
#include <unordered_map>
#include <memory>

class Factory
{
    static const std::unordered_map<eOperandType, std::unique_ptr<IOperand> (Factory::*)(const std::string &)> _operands;
    static std::shared_ptr<Factory> _instance;
    std::unique_ptr<IOperand> createInt8(const std::string& value) { return std::make_unique<Int8>(value); };
    std::unique_ptr<IOperand> createInt16(const std::string& value) { return std::make_unique<Int16>(value); };
    std::unique_ptr<IOperand> createInt32(const std::string& value) { return std::make_unique<Int32>(value); };
    std::unique_ptr<IOperand> createFloat(const std::string& value) { return std::make_unique<Float>(value); };
    std::unique_ptr<IOperand> createDouble(const std::string& value) { return std::make_unique<Double>(value); };
    std::unique_ptr<IOperand> createBigDecimal(const std::string& value) { return std::make_unique<BigDecimal>(value); };
public:
    Factory() {};
    ~Factory() {};
    static std::unique_ptr<IOperand> createOperand(eOperandType type, const std::string &value);
};