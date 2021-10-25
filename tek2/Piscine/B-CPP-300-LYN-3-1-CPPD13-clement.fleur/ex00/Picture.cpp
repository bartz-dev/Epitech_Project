/*
** EPITECH PROJECT, 2021
** encapsulation
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream stream(file.data());
    std::stringstream buffer;

    if (stream.is_open()) {
        buffer << stream.rdbuf();
        this->data = buffer.str();
        return true;
    }
    this->data = "ERROR";
    return false;
}
