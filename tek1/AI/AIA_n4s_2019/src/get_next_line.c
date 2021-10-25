/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** get_next_line.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"
#include "n4s.h"

char *get_next_line(const int fd)
{
    static t_vars	var;

    if ((var.id == 0 && (var.value = read(fd, var.buf, 1)) < 1)
        || (var.id_line == 0 && (var.line = malloc(SIZE_MALLOC)) == NULL))
    exit(write(2, "exit\n", 5));
    while (var.id != var.value) {
        if (var.buf[var.id] == '\n' || var.buf[var.id] == 0) {
            var.id += 1;
            var.line[var.id_line] = 0;
            var.id_line = 0;
            return (var.line);
        }
        var.line[var.id_line] = var.buf[var.id];
        var.id_line += 1;
        var.id += 1;
    }
    var.id = 0;
    get_next_line(fd);
    return (var.line);
}
