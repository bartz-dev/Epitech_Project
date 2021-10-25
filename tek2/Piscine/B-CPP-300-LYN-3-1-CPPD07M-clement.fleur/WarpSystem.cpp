/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-clement.fleur
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"
#include "Federation.hpp"

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    this->_coreReactor = coreReactor;
}

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return this->_coreReactor;
}