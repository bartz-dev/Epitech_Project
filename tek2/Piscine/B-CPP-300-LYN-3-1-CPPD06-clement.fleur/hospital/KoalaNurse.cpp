/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-clement.fleur
** File description:
** KoalaNurse.cpp
*/

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)
{
    this->id = id;
    this->working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id << ": Finally some rest!" << std::endl;
    this->id = 0;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *SickKoala)
{
     if (SickKoala)
        SickKoala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream file (filename.c_str(), std::ios::in);
    std::string koala = "";
    std::string drug;

    if (file) {
        if (filename.find(".report") == std::string::npos)
            return koala;
        koala = filename.substr(filename.find_last_of(".")) == ".report" ?
        filename.substr(0, filename.find(".")) : "";
        if (koala == "" || !getline(file, drug))
            return "";
        std::cout << "Nurse " << this->id << ": Kreog! Mr." << koala << " needs a "
        << drug << "!" << std::endl;
    } else
        return "";
    return drug;
}

void KoalaNurse::timeCheck()
{
    std::string work = !this->working ? "get to work!" : "go home to my eucalyptus forest!";

    std::cout << "Nurse " << this->id << ": Time to " << work << std::endl;
    this->working = !this->working;
}