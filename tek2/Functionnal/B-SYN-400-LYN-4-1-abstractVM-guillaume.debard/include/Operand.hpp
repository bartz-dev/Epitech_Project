/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-guillaume.debard
** File description:
** Operand
*/

#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <compare>

template <typename T>
    concept IsOperand = std::is_arithmetic_v<T>;

typedef enum eOperandType
{
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL
} eOperandType;

class IOperand
{
public:
    virtual std::string const & toString() const = 0;
    virtual eOperandType getType() const = 0;
    virtual std::unique_ptr<IOperand const> operator+(const IOperand &) const = 0;
    virtual std::unique_ptr<IOperand const> operator-(const IOperand &) const = 0;
    virtual std::unique_ptr<IOperand const> operator*(const IOperand &) const = 0;
    virtual std::unique_ptr<IOperand const> operator/(const IOperand &) const = 0;
    virtual std::unique_ptr<IOperand const> operator%(const IOperand &) const = 0;
    virtual std::partial_ordering operator<=>(const IOperand &) const = 0;
    virtual bool operator==(const IOperand &) const = 0;
    virtual ~IOperand() {}
};

template <IsOperand T>
class Operand : public IOperand
{
    public:
        virtual std::string const &toString() const override;
        virtual eOperandType getType() const override;
        std::unique_ptr<IOperand const> operator+(const IOperand &target) const override;
        std::unique_ptr<IOperand const> operator-(const IOperand &target) const override;
        std::unique_ptr<IOperand const> operator*(const IOperand &target) const override;
        std::unique_ptr<IOperand const> operator/(const IOperand &target) const override;
        std::unique_ptr<IOperand const> operator%(const IOperand &target) const override;
        std::partial_ordering operator<=>(const IOperand &rhs) const override;
        bool operator==(const IOperand &rhs) const override;
        Operand(eOperandType type, const std::string & value);
        ~Operand();

    protected:
        std::string value;
        eOperandType type;
};

class Int8 : public Operand<int8_t>
{
public:
    Int8(std::string const &value);
    ~Int8() {}
};

class Int16 : public Operand<int16_t>
{
public:
    Int16(std::string const &value);
    ~Int16() {}
};

class Int32 : public Operand<int32_t>
{
public:
    Int32(std::string const &value);
    ~Int32() {}
};

class Float : public Operand<float>
{
public:
    Float(std::string const &value);
    ~Float() {}
};

class Double : public Operand<double>
{
public:
    Double(std::string const &value);
    ~Double() {}
};

class BigDecimal : public Operand<long double>
{
public:
    BigDecimal(std::string const &value);
    ~BigDecimal() {}
};