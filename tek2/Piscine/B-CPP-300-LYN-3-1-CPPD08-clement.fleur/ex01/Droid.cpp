/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD08-clement.fleur
** File description:
** Droid.cpp
*/

#include "Droid.hpp"
#include <iostream>

Droid::Droid(std::string str): Serial(str), Energy(50), Attack(25), Toughness(15)
{
    this->status = new std::string("Standing by");
    std::cout << "Droid '" << this->Serial << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : Serial(droid.Serial), Energy(droid.Energy), Attack(droid.Attack), Toughness(droid.Toughness)
{
    this->status = droid.status ? new std::string(*droid.status) : new std::string("Standing by");

    std::cout << "Droid '" << this->Serial << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->Serial << "' Destroyed" << std::endl;
    delete this->status;
}

std::string Droid::getId() const
{
    return this->Serial;
}

size_t Droid::getEnergy() const
{
    return this->Energy;
}

size_t Droid::getAttack() const
{
    return this->Attack;
}

size_t Droid::getToughness() const
{
    return this->Toughness;
}

std::string *Droid::getStatus() const
{
    return this->status;
}

void Droid::setId(std::string new_serial)
{
    this->Serial = new_serial;
}

void Droid::setEnergy(size_t new_energy)
{
    this->Energy = new_energy;
}

void Droid::setStatus(std::string *new_status)
{
    this->status = new_status;
}

bool Droid::operator==(Droid const &droid) const
{
    return this->Serial == droid.Serial &&
    this->Energy == droid.Energy &&
    this->Attack == droid.Attack &&
    this->Toughness == droid.Toughness &&
    *this->status == *droid.status;
}

bool Droid::operator!=(Droid const &droid) const
{
    return !(*this == droid);
}

Droid& Droid::operator=(Droid const &droid)
{
    this->Serial = droid.Serial;
    this->Energy = droid.Energy;
    this->status = new std::string(*droid.status);

    return *this;
}

std::ostream& operator<<(std::ostream &os, const Droid &droid)
{
    if (droid.getEnergy() > 100)
        return os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", 100";
    else
        return os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
}

Droid& Droid::operator<<(size_t &energy)
{
    size_t value = 100 - this->Energy;

    if (this->Energy < 100) {
        this->Energy = this->Energy + (100 - this->Energy);
        energy = energy - value;
    }
    return *this;
}

DroidMemory *Droid::getBattleData() const
{
    return this->BattleData;
}

void Droid::setBattleData(DroidMemory *droid_memory)
{
    this->BattleData = droid_memory;
}