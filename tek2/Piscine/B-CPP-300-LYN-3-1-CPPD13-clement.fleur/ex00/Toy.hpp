/*
** EPITECH PROJECT, 2021
** toy
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };

        Toy();
        virtual ~Toy();
        Toy(ToyType type, std::string const &name, std::string const &ascii);
        Toy(Toy const &toy);

        //getter
        int getType() const;
        const std::string &getName() const;
        const std::string &getAscii() const;

        //setter
        void setName(const std::string &name);
        bool setAscii(const std::string &ascii);

    protected:
        ToyType type;
        std::string name;
        Picture picture;
    private:
};

#endif /* !TOY_HPP_ */
