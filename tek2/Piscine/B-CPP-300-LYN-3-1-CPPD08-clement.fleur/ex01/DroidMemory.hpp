/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD08-clement.fleur
** File description:
** DroidMemory.hpp
*/

#ifndef DROID_MEMORY_D
#define DROID_MEMORY_D

#include <string>

class DroidMemory
{
    size_t Fingerprint;
    size_t Exp;

    public:
        DroidMemory();
        ~DroidMemory();

        //Getter
        size_t getFingerPrint() const;
        size_t getExp() const;

        //setter
        void setFingerPrint(size_t new_finger_print);
        void setExp(size_t new_exp);

        // operator
        DroidMemory& operator<<(DroidMemory const &droid_memory);
        DroidMemory& operator>>(DroidMemory &droid_memory) const;
        DroidMemory& operator+=(DroidMemory const &droid_memory);
        DroidMemory& operator+=(size_t new_exp);
        DroidMemory& operator+(DroidMemory const &droid_memory) const;
        DroidMemory& operator+(size_t new_exp) const;
};

std::ostream& operator<<(std::ostream& os, DroidMemory const &droid_memory);

#endif // !DROID_MEMORY_D