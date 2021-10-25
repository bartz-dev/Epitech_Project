/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-martin.rougeron
** File description:
** vertex
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"
#include <math.h>
#include <stdlib.h>

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("VertexClass null error at init");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this)
        this = NULL;
    else
        raise("No this");
}

static char *Vertex_str(VertexClass *this)
{
    char *string = malloc(sizeof(floor(log10(abs(this->x))) + 1) +
    sizeof(floor(log10(abs(this->y))) + 1) +
    sizeof(floor(log10(abs(this->z))) + 1) + 19);
    if (!(this))
        raise("Null VertexClass");
    sprintf(string, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return string;
}
// Create additional functions here

static Object *Vertex_add(const Object *this, const Object *this2)
{
    VertexClass *this_class = (VertexClass *)(this);
    VertexClass *this2_class = (VertexClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return new(Vertex, this_class->x + this2_class->x,
    this_class->y + this2_class->y, this_class->z + this2_class->z);
}

static Object *Vertex_sub(const Object *this, const Object *this2)
{
    VertexClass *this_class = (VertexClass *)(this);
    VertexClass *this2_class = (VertexClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return new(Vertex, this_class->x - this2_class->x,
    this_class->y - this2_class->y, this_class->z - this2_class->z);
}

static Object *Vertex_mult(const Object *this, const Object *this2)
{
    VertexClass *this_class = (VertexClass *)(this);
    VertexClass *this2_class = (VertexClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return new(Vertex, this_class->x * this2_class->x,
    this_class->y * this2_class->y,
    this_class->z * this2_class->z);
}

static Object *Vertex_div(const Object *this, const Object *this2)
{
    VertexClass *this_class = (VertexClass *)(this);
    VertexClass *this2_class = (VertexClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return new(Vertex, this_class->x / this2_class->x,
    this_class->y / this2_class->y,
    this_class->z / this2_class->z);
}

bool Vertex_eq(const Object *this, const Object *this2)
{
    VertexClass *this_class = (VertexClass *)(this);
    VertexClass *this2_class = (VertexClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return (this_class->x == this2_class->x &&
    this_class->y == this2_class->y &&
    this_class->z == this2_class->z);
}

bool Vertex_gt(const Object *this, const Object *this2)
{
    VertexClass *this_class = (VertexClass *)(this);
    VertexClass *this2_class = (VertexClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return this_class->x > this2_class->x &&
    this_class->y > this2_class->y && this_class->z > this2_class->z ? 1 : 0;
}

bool Vertex_lt(const Object *this, const Object *this2)
{
    VertexClass *this_class = (VertexClass *)(this);
    VertexClass *this2_class = (VertexClass *)(this2);

    if (!(this_class) || !(this2_class))
        raise("Null VertexClass add");
    return this_class->x < this2_class->x &&
    this_class->y < this2_class->y && this_class->z < this2_class->z ? 1 : 0;
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str, /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Vertex_mult,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = (binary_comparator_t)&Vertex_gt,
        .__lt__ = (binary_comparator_t)&Vertex_lt
    },
    .x = 0,
    .y = 0,
    .z = 0,
};

const Class   *Vertex = (const Class *)&_description;
