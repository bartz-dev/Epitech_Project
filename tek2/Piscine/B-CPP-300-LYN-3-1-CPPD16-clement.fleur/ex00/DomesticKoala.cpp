/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-clement.fleur
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &koala_action) : _koala_action(koala_action), _action(1024)
{
}

DomesticKoala::DomesticKoala(DomesticKoala const &copy) : _koala_action(copy._koala_action), _action(copy._action)
{
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala &DomesticKoala::operator=(DomesticKoala const &copy)
{
    _action = copy._action;
    _koala_action = copy._koala_action;
    return *this;
}

std::vector<DomesticKoala::methodPointer_t> const *DomesticKoala::getActions() const
{
    return &_action;
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _action[command] = action;
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    _action[command] = nullptr;
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    methodPointer_t exec = _action[command];

    if (exec)
        (_koala_action.*exec)(param);
}

void DomesticKoala::setKoalaAction(KoalaAction &koala_action)
{
    _koala_action = koala_action;
}