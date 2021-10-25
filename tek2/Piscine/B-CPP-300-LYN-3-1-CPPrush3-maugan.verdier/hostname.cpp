/*
** EPITECH PROJECT, 2020
** MyGKrellM
** File description:
** hostname.hpp
*/

#include "MyGKrellM.hpp"
#include <unistd.h>
#include <string>

int GKrellm::update_hostname(void)
{
    char hostname[64] = {0};

    if (gethostname(hostname, 64) == -1)
        return -1;
    this->_hostname = hostname;
    return 0;
}
