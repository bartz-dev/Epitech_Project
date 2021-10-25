/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush1-martin.rougeron
** File description:
** char.c
*/

#include <stdio.h>
#include "char.h"
#include "new.h"
#include <math.h>
#include <stdlib.h>

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Char null error at init");
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (this)
        this = NULL;
    else
        raise("No this");
}

static char *Char_str(CharClass *this)
{
    char *string = malloc(sizeof(char) + 11);
    if (!(this))
        raise("Null Char");
    sprintf(string, "<Char (%c)>", this->x);
    return string;
}
// Create additional functions here

static Object *Char_add(const Object *this, const Object *this2)
{
    CharClass *this_class = (CharClass *)(this);
    CharClass *this2_class = (CharClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Char add");
    return new(Char, this_class->x + this2_class->x);
}

static Object *Char_sub(const Object *this, const Object *this2)
{
    CharClass *this_class = (CharClass *)(this);
    CharClass *this2_class = (CharClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Char add");
    return new(Char, this_class->x - this2_class->x);
}

static Object *Char_mult(const Object *this, const Object *this2)
{
    CharClass *this_class = (CharClass *)(this);
    CharClass *this2_class = (CharClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Char add");
    return new(Char, this_class->x * this2_class->x);
}

static Object *Char_div(const Object *this, const Object *this2)
{
    CharClass *this_class = (CharClass *)(this);
    CharClass *this2_class = (CharClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Char add");
    if (this2_class->x == 0)
        raise("Error can't divise by 0");
    return new(Char, this_class->x / this2_class->x);
}

bool Char_eq(const Object *this, const Object *this2)
{
    CharClass *this_class = (CharClass *)(this);
    CharClass *this2_class = (CharClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Char add");
    return (this_class->x == this2_class->x);
}

bool Char_gt(const Object *this, const Object *this2)
{
    CharClass *this_class = (CharClass *)(this);
    CharClass *this2_class = (CharClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Char add");
    return this_class->x > this2_class->x;
}

bool Char_lt(const Object *this, const Object *this2)
{
    CharClass *this_class = (CharClass *)(this);
    CharClass *this2_class = (CharClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Char add");
    return this_class->x < this2_class->x;
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str, /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Char_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Char_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Char_mult,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0,
};

const Class   *Char = (const Class *)&_description;