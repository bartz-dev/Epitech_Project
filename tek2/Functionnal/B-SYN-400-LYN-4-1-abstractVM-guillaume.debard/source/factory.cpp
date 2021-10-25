/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** factory
*/

#include "Operand.hpp"
#include "Factory.hpp"
#include <functional>

using FactoryMap = std::unordered_map<eOperandType, std::unique_ptr<IOperand>(Factory::*)(const std::string &)>;

std::shared_ptr<Factory> Factory::_instance = std::make_shared<Factory>();
const FactoryMap Factory::_operands = {
  {INT8, &Factory::createInt8},
  {INT16, &Factory::createInt16},
  {INT32, &Factory::createInt32},
  {FLOAT, &Factory::createFloat},
  {DOUBLE, &Factory::createDouble},
  {BIGDECIMAL, &Factory::createBigDecimal}
};

std::unique_ptr<IOperand> Factory::createOperand(eOperandType type, const std::string &value)
{
    std::string clean_val = (type < FLOAT) ? value.substr(0, value.find(".", 0)) : value;
    auto method = std::bind(_operands.at(type), &(*_instance), clean_val);
    return method();
}