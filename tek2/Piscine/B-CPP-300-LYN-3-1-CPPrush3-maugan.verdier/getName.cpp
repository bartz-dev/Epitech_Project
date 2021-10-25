/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** getName.cpp
*/

#include "MyGKrellM.hpp"
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

std::string getName()
{
    uid_t id = getuid();
    struct passwd *info = getpwuid(id);
    std::string text(info->pw_name);

    return text;
}

void GKrellm::update_username()
{
    this->_username = getName();
}
