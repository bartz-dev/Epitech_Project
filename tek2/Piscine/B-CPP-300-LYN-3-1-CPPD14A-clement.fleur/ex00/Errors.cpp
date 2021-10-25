/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14A-clement.fleur
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) : _message(message), _component(component)
{
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
}

std::string const &NasaError::getComponent() const
{
    return _component;
}