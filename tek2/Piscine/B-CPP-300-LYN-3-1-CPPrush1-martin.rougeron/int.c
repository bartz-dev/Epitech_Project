/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-martin.rougeron
** File description:
** vertex
*/

#include <stdio.h>
#include "int.h"
#include "new.h"
#include <math.h>
#include <stdlib.h>

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("Int null error at init");
    if (!args)
        raise("Null args error at init");
    this->x = (int)va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    if (this)
        this = NULL;
    else
        raise("No this");
}

static char *Int_str(IntClass *this)
{
    char *string = malloc(sizeof(floor(log10(abs(this->x))) + 1) + 10);
    if (!(this))
        raise("Null Int");
    sprintf(string, "<Int (%d)>", this->x);
    return string;
}
// Create additional functions here

static Object *Int_add(const Object *this, const Object *this2)
{
    IntClass *this_class = (IntClass *)(this);
    IntClass *this2_class = (IntClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Int add");
    return new(Int, this_class->x + this2_class->x);
}

static Object *Int_sub(const Object *this, const Object *this2)
{
    IntClass *this_class = (IntClass *)(this);
    IntClass *this2_class = (IntClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Int add");
    return new(Int, this_class->x - this2_class->x);
}

static Object *Int_mult(const Object *this, const Object *this2)
{
    IntClass *this_class = (IntClass *)(this);
    IntClass *this2_class = (IntClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Int add");
    return new(Int, this_class->x * this2_class->x);
}

static Object *Int_div(const Object *this, const Object *this2)
{
    IntClass *this_class = (IntClass *)(this);
    IntClass *this2_class = (IntClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Int add");
    if (this2_class->x == 0)
        raise("Error can't divise by 0");
    return new(Int, this_class->x / this2_class->x);
}

bool Int_eq(const Object *this, const Object *this2)
{
    IntClass *this_class = (IntClass *)(this);
    IntClass *this2_class = (IntClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Int add");
    return (this_class->x == this2_class->x);
}

bool Int_gt(const Object *this, const Object *this2)
{
    IntClass *this_class = (IntClass *)(this);
    IntClass *this2_class = (IntClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Int add");
    return this_class->x > this2_class->x;
}

bool Int_lt(const Object *this, const Object *this2)
{
    IntClass *this_class = (IntClass *)(this);
    IntClass *this2_class = (IntClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Int add");
    return this_class->x < this2_class->x;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str, /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Int_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Int_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Int_mult,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0,
};

const Class   *Int = (const Class *)&_description;