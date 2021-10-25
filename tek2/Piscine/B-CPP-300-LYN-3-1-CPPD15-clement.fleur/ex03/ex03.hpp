/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-clement.fleur
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename T>
void foreach(const T *array,  void (&func)(const T &elem), int size)
{
    for (int i = 0; i < size; i++)
        func(array[i]);
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}


#endif /* !EX02_HPP_ */