/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#include <math.h>
#include <stdlib.h>
typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;


static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        raise("PointClass null error at init");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this)
        this = NULL;
    else
        raise("No this");
}

static char *Point_str(PointClass *this)
{
    char *string = malloc(sizeof(floor(log10(abs(this->x))) + 1) +
    sizeof(floor(log10(abs(this->y))) + 1) + 15);
    if (!(this))
        raise("Null pointClass str");
    sprintf(string, "<Point (%d, %d)>", this->x, this->y);
    return string;
}
// Create additional functions here

static Object *Point_add(const Object *this, const Object *this2)
{
    PointClass *this_class = (PointClass *)(this);
    PointClass *this2_class = (PointClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null pointClass add");
    return new(Point, this_class->x + this2_class->x, this_class->y + this2_class->y);
}

static Object *Point_sub(const Object *this, const Object *this2)
{
    PointClass *this_class = (PointClass *)(this);
    PointClass *this2_class = (PointClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null pointClass add");
    return new(Point, this_class->x - this2_class->x, this_class->y - this2_class->y);
}

static Object *Point_mult(const Object *this, const Object *this2)
{
    PointClass *this_class = (PointClass *)(this);
    PointClass *this2_class = (PointClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null pointClass add");
    return new(Point, this_class->x * this2_class->x,
    this_class->y * this2_class->y);
}

static Object *Point_div(const Object *this, const Object *this2)
{
    PointClass *this_class = (PointClass *)(this);
    PointClass *this2_class = (PointClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null pointClass add");
    if (this2_class->x == 0)
        raise("Error can't divise by 0");
    return new(Point, this_class->x / this2_class->x,
    this_class->y / this2_class->y);
}

bool Point_eq(const Object *this, const Object *this2)
{
    PointClass *this_class = (PointClass *)(this);
    PointClass *this2_class = (PointClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null pointClass add");
    return (this_class->x == this2_class->x &&
    this_class->y == this2_class->y);
}

bool Point_lt(const Object *this, const Object *this2)
{
    PointClass *this_class = (PointClass *)(this);
    PointClass *this2_class = (PointClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return this_class->x < this2_class->x && this_class->y < this2_class->y ?
    1 : 0;
}

bool Point_gt(const Object *this, const Object *this2)
{
    PointClass *this_class = (PointClass *)(this);
    PointClass *this2_class = (PointClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return this_class->x > this2_class->x && this_class->y > this2_class->y ?
    1 : 0;
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str, /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Point_mult,
        .__div__ = (binary_operator_t)&Point_div,
        .__eq__ = (binary_comparator_t)&Point_eq,
        .__gt__ = (binary_comparator_t)&Point_gt,
        .__lt__ = (binary_comparator_t)&Point_lt
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
