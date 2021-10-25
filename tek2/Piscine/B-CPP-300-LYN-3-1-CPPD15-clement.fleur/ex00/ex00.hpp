/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-clement.fleur
** File description:
** ex00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template <typename T>
void swap(T &first, T &second)
{
    T tmp = first;
    first = second;
    second = tmp;
}

template <typename T>
const T &min(const T &first, const T &second)
{
    return first > second ? second : first;
}

template <typename T>
const T &max(const T &first, const T &second)
{
    return first < second ? second : first;
}

template <typename T>
const T add (const T &first, const T &second)
{
    return first + second;
}


#endif /* !EX00_HPP_ */
