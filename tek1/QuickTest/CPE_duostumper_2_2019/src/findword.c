/*
** EPITECH PROJECT, 2020
** findword
** File description:
** 
*/

#include "my.h"

typedef struct var {
    int pos2;
    int pos;
    
} var_t;

int findword_scd(char *word, int size, char *arg, var_t *t)
{
    if (word[t->pos2] == arg[t->pos + size]) { arg[t->pos + size] -= 32;
        t->pos += size;
        t->pos2++;
    }
    if (word[t->pos2] == arg[t->pos - size]) { arg[t->pos - size] -= 32;
        t->pos2++;
        t->pos -= size;
    }
}

int findword(char *word, int size, char *arg)
{
    int count = my_strlen(word);
    int i = 1;
    var_t t = { 0 };

    while (arg[t.pos] != word[t.pos2])
        t.pos++;
    t.pos2++;
    while (i != count) {
        if (word[t.pos2] == arg[t.pos--]) { arg[t.pos--] -= 32;
            t.pos--;
            t.pos2++;
        }
        if (word[t.pos2] == arg[t.pos++]) { arg[t.pos++] -= 32; 
            t.pos++;
            t.pos2++;
        }
        findword_scd(word, size, arg, &t);
        i++;
    }
    printf("%s\n", arg);
}
