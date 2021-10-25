/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Object
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

class Object {
    public:
        Object(const std::string &title);
        virtual ~Object();
        const std::string getTitle() const;

        void setTitle(const std::string &title);

    protected:
        std::string _title;
    private:
};

#endif /* !OBJECT_HPP_ */
