/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** date_time.cpp
*/

#include "MyGKrellM.hpp"
#include <iostream>
#include <chrono>
#include <ctime>    

std::time_t date_time()
{
    auto chrono = std::chrono::system_clock::now();

    std::time_t chrono_time = std::chrono::system_clock::to_time_t(chrono);
    //std::cout << std::ctime(&chrono_time); //Commande pour afficher mettre en commentaire dans cette fonction
    return chrono_time;
}

void GKrellm::update_datetime()
{
    this->_time = date_time();
}