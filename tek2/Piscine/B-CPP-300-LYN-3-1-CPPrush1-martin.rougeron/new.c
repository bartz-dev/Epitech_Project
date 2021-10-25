/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-martin.rougeron
** File description:
** new
*/

#include "new.h"
#include "player.h"
#include "vertex.h"
#include "point.h"
#include "object.h"

Object *va_new(const  Class *class, va_list *ap)
{
    Object *obj;

    obj = malloc((*class).__size__);
    if (!obj)
        raise("Out of memory");
    memcpy(obj, class, (*class).__size__);
    if ((*class).__ctor__)
        (*class).__ctor__(obj, ap);
    return (obj);
}

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *obj;

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return (obj);
}

void delete(Object *ptr) {
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}