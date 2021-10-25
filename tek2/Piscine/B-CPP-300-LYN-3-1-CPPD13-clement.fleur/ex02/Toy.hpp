/*
** EPITECH PROJECT, 2021
** toy
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy
{
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            WOODY,
            BUZZ
        };

        Toy();
        virtual ~Toy();
        Toy(ToyType type, std::string const &name, std::string const &ascii);
        Toy(const Toy &toy);

        //getter
        int getType() const;
        const std::string &getName() const;
        const std::string &getAscii() const;

        //setter
        void setName(const std::string &name);
        bool setAscii(const std::string &ascii);

        //operator
        Toy &operator=(const Toy &toy);
        Toy &operator<<(const std::string &ascii);

    protected:
        ToyType type;
        std::string name;
        Picture picture;

    private:
};

#endif /* !TOY_HPP_ */
