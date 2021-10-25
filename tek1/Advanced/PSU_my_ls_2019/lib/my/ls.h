/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** ls.h
*/

#ifndef _LS__
#define _LS__

typedef struct ls_s
{
    char *arg;
    int l;
    int r;
    int t;
    int i;
    int check;
    int dir;
    int count;
    int checkend;
    int ac;
} ls_t;

char *checkarg(char *argv, ls_t *ls);
int check_path(char *arg, ls_t *ls);
int my_ls(char *directory, ls_t *ls);
void checkdescription(char *arg, ls_t *ls);
void alphabeticalshort(char *directory, ls_t *ls);
void redirect(char *directory, ls_t *ls);
void l_flag(char *name);
void no_flag(char *directory);

#endif