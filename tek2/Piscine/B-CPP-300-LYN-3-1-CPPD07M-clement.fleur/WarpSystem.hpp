/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-clement.fleur
** File description:
** WarpSystem.hpp
*/


#ifndef WARPSYSTEM_D
#define WARPSYSTEM_D

namespace WarpSystem
{
    class QuantumReactor
    {
        bool _stability;

        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability);
    };
    class Core
    {
        QuantumReactor *_coreReactor;

        public:
            Core(QuantumReactor *coreReactor);
            QuantumReactor *checkReactor();
    };
}

#endif // !WARPSYSTEM_D