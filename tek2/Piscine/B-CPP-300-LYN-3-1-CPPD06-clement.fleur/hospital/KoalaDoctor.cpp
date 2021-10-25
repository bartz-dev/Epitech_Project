/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** KoalaDoctor.cpp
*/

#include "KoalaDoctor.hpp"
#include "KoalaNurse.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->work = false;
    std::cout << "Dr." << this->name << ": I'm Dr." << this->name
    << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
    this->name.clear();
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    int drug_index = random()%5;
    std::string drug[5] = {"Mars", "Kinder", "Crunch",
                           "Maroilles", "Eucalyptus Leaf"};
    std::string file = koala->getName() + ".report";
    std::ofstream stream;

    koala->poke();
    std::cout << "Dr." << this->name << ": So what's goerking you Mr."
    << koala->name << "?" << std::endl;
    stream.open(file.c_str());
    if (stream.is_open())
        stream << drug[drug_index];
}

void KoalaDoctor::timeCheck()
{
    std::string work = this->work ? "get to work!" : "go home to my eucalyptus forest!";

    std::cout << "Dr." << this->name << ": Time to " << work << std::endl;
    this->work = !this->work;
}