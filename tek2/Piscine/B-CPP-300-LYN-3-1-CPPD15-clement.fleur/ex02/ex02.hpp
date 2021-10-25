/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-clement.fleur
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template <typename T>
const T &min(const T &first, const T &second)
{
    std::cout << "template min" << std::endl;

    return first <= second ? first : second;
}

int min(int first, int second)
{
    std::cout << "non-template min" << std::endl;

    if (first <= second)
        return first;
    return second;
}

template <typename T>
const T &templateMin(const T *array, int size)
{
    T &res = const_cast<T&>(array[0]);

    for (int i = 1; i < size; i++)
        res = min<T>(array[i], res);
    return res;
}

int nonTemplateMin(int *array, int size)
{
    int res = array[0];

    for (int i = 1; i < size; i++)
        res = min(array[i], res);
    return res;
}

#endif /* !EX02_HPP_ */
