/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-clement.fleur
** File description:
** DomesticKoala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include "KoalaAction.hpp"
#include <iostream>
#include <vector>

class DomesticKoala
{
    public:
        explicit DomesticKoala(KoalaAction &koala_action);
        explicit DomesticKoala(const DomesticKoala &copy);
        ~DomesticKoala();
        typedef void (KoalaAction::*methodPointer_t)(const std::string &param);
        DomesticKoala &operator=(const DomesticKoala &copy);


        const std::vector<methodPointer_t> *getActions(void) const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &koala_action);
    private:
        KoalaAction _koala_action;
        std::vector<methodPointer_t> _action;
};

#endif /* !DOMESTICKOALA_HPP_ */
