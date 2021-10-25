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

Picture::Picture(Picture const &picture) : data(picture.data)
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
    std::string buffer;

    if (stream) {
        this->data = "";
        while (getline(stream, buffer, '\0'))
            this->data += buffer;
        stream.close();
        return true;
    }
    else {
        this->data = "ERROR";
        return false;
    }

}

Picture &Picture::operator=(const Picture &picture)
{
    if (this->data != picture.data)
        this->data = picture.data;
    return *this;
}
