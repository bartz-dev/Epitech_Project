/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-clement.fleur
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <string>
#include <cstring>

template<typename T>
int compare(const T &first, const T &second)
{
    return first > second ? 1 :
    first == second ? 0 : -1;
}

template<>
int compare<const char *>(const char *const &first, const char *const &second)
{
    int res = strcmp(first, second);

    return res < 0 ? -1 : res > 0 ? 1 : 0;
}

#endif /* !EX01_HPP_ */
