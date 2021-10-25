/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-clement.fleur
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename T>
typename T::iterator do_find(T &container, int search)
{
    return std::find(container.begin(), container.end(), search);
}


#endif /* !FIND_HPP_ */
