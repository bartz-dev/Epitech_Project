/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>

/*UTILS*/
void my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
char *my_revstr(char *str);
/*UTILS*/
/*PROG*/
void help();
int my_factrec_synthesis(int nb);
int my_squareroot_synthesis(int nb);
int my_strcmp(char const *s1, char const *s2);
char *baseconv(char *string, int nbr, int base);
/*PROG*/
/*ERROR*/
int check_int(char **av, int ac);
int check_base(char **av, int ac);
int check_nbr(char **av, int ac);
/*ERROR*/