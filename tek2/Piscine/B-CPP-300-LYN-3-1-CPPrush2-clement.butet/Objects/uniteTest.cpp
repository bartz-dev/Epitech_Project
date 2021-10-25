/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** uniteTest
*/

#include "Teddy.hpp"
#include "Toy.hpp"
#include "LittlePony.hpp"

Object **MyUnitTests()
{
	auto array = new Object*[2];

	array[0] = new LittlePony("happy pony");
	array[1] = new Teddy("tedddd");
	return (array);
}

int main()
{
    Object **array = MyUnitTests();

    std::cout << "pony is " << ((Toy *)array[0])->getName() << std::endl;
    std::cout << "ted is " << ((Toy *)array[1])->getName() << std::endl;
    delete[] array;
    return (0);
}