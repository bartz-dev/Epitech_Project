/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "../Wrap/Wrap.hpp"
#include "../Objects/Teddy.hpp"

class Box : public Wrap {
    public:
        Box(std::string const& name);
        ~Box();
        virtual bool isOpen() const;
        virtual void CloseMe();
        virtual void OpenMe();

    protected:
        bool _open;
        Teddy *teddy;

    private:
};

#endif /* !BOX_HPP_ */