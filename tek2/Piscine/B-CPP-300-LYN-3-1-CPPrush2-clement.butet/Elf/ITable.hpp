/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-clement.butet
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "../Objects/Object.hpp"

class ITable {
    public:
        ITable();
        ~ITable();

        ITable *createTable();
        void PushIN(Object *object);
        void PushOUT();
        void PutObject(Object *object);
        Object *takeObject();

    protected:
        int _onTable;
        Object *item = NULL;
    private:
};

#endif /* !ITABLE_HPP_ */
