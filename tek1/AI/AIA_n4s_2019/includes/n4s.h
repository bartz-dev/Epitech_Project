/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** n4s.h
*/

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct nfs_s
{
    char *start;
    char *dir;
    char *pos;
    char *stop;
    char *cmd;
    char **arr;
    float axis;
} nfs_t;

void init_struct(nfs_t *nfs);
char *get_next_line(const int fd);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(char *str);
int	my_strlen(char *str);
int get_pos(char *str, int fd, nfs_t *nfs);
char *check_str(char *str);
char **my_strtotab(char *str, char lim);
float my_atof(char *str);
int	get_speed(float mid, nfs_t *nfs);
int	check_dir(char **tab, float line, nfs_t *nfs);
int	check_management(float id, char *val, nfs_t *nfs);
int check_pos(char *str, nfs_t *nfs);
void my_putchar(char c);
int get_littlespeed(float line, nfs_t *nfs);
char **receive_str(nfs_t *nfs);
char *my_malloc(int len);