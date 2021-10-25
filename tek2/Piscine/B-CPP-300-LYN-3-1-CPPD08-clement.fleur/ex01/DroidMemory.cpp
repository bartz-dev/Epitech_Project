/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD08-clement.fleur
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"
#include <stdlib.h>
#include <iostream>

DroidMemory::DroidMemory() : Exp(0)
{
    this->Fingerprint = random();
}

DroidMemory::~DroidMemory()
{

}

size_t DroidMemory::getFingerPrint() const
{
    return this->Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return this->Exp;
}

void DroidMemory::setFingerPrint(size_t new_finger_print)
{
    this->Fingerprint =  new_finger_print;
}

void DroidMemory::setExp(size_t new_exp)
{
    this->Exp = new_exp;
}

DroidMemory& DroidMemory::operator<<(DroidMemory const &droid_memory)
{
    this->Fingerprint =  this->Fingerprint ^ droid_memory.getFingerPrint();
    this->Exp = this->Exp + droid_memory.getExp();

    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory &droid_memory) const
{
    droid_memory.setFingerPrint(droid_memory.getFingerPrint() ^ this->getFingerPrint());
    droid_memory.setExp(droid_memory.getExp() + this->getExp());

    return droid_memory;
}

DroidMemory& DroidMemory::operator+=(DroidMemory const &droid_memory)
{
    this->Fingerprint =  this->Fingerprint ^ droid_memory.getFingerPrint();
    this->Exp = this->Exp + droid_memory.getExp();

    return *this;
}

DroidMemory& DroidMemory::operator+=(size_t new_exp)
{
    this->Exp = this->Exp + new_exp;
    this->Fingerprint = this->Fingerprint ^ new_exp;

    return *this;
}

DroidMemory& DroidMemory::operator+(DroidMemory const &droid_memory) const
{
  DroidMemory *temp = new DroidMemory();
  temp->Fingerprint = this->Fingerprint ^ droid_memory.getFingerPrint();
  temp->Exp = this->Exp + droid_memory.getExp();
  return *temp;
}

DroidMemory& DroidMemory::operator+(size_t new_exp) const
{
    DroidMemory *temp = new DroidMemory();

    temp->Exp = this->Exp + new_exp;
    temp->Fingerprint = this->Fingerprint ^ new_exp;

    return *temp;

}

std::ostream& operator<<(std::ostream& os, DroidMemory const& droid_memory) {
  os << "DroidMemory '" << droid_memory.getFingerPrint() << "', " << droid_memory.getExp();

  return (os);
}