/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush1-martin.rougeron
** File description:
** float.c
*/
/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-martin.rougeron
** File description:
** vertex
*/

#include <stdio.h>
#include "float.h"
#include "new.h"
#include <math.h>
#include <stdlib.h>

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Float null error at init");
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (this)
        this = NULL;
    else
        raise("No this");
}

static char *Float_str(FloatClass *this)
{
    char *string = malloc(sizeof(floor(log10(abs(this->x))) + 1) + 10);
    if (!(this))
        raise("Null Float");
    sprintf(string, "<Float (%f)>", this->x);
    return string;
}
// Create additional functions here

static Object *Float_add(const Object *this, const Object *this2)
{
    FloatClass *this_class = (FloatClass *)(this);
    FloatClass *this2_class = (FloatClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Float add");
    return new(Float, this_class->x + this2_class->x);
}

static Object *Float_sub(const Object *this, const Object *this2)
{
    FloatClass *this_class = (FloatClass *)(this);
    FloatClass *this2_class = (FloatClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Float add");
    return new(Float, this_class->x - this2_class->x);
}

static Object *Float_mult(const Object *this, const Object *this2)
{
    FloatClass *this_class = (FloatClass *)(this);
    FloatClass *this2_class = (FloatClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Float add");
    return new(Float, this_class->x * this2_class->x);
}

static Object *Float_div(const Object *this, const Object *this2)
{
    FloatClass *this_class = (FloatClass *)(this);
    FloatClass *this2_class = (FloatClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Float add");
    if (this2_class->x == 0)
        raise("Error can't divise by 0");
    return new(Float, this_class->x / this2_class->x);
}

bool Float_eq(const Object *this, const Object *this2)
{
    FloatClass *this_class = (FloatClass *)(this);
    FloatClass *this2_class = (FloatClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Float add");
    return (this_class->x == this2_class->x);
}

bool Float_gt(const Object *this, const Object *this2)
{
    FloatClass *this_class = (FloatClass *)(this);
    FloatClass *this2_class = (FloatClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Float add");
    return this_class->x > this2_class->x;
}

bool Float_lt(const Object *this, const Object *this2)
{
    FloatClass *this_class = (FloatClass *)(this);
    FloatClass *this2_class = (FloatClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null Float add");
    return this_class->x < this2_class->x;
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str, /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Float_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Float_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Float_mult,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0,
};

const Class   *Float = (const Class *)&_description;