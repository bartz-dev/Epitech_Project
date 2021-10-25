/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** palindrome.h
*/

#ifndef PALINDROME
#define PALINDROME

typedef struct palindrome_t
{
    int base;
    int number;
    int imin;
    int imax;
    char *palin;
} palindrome;

int palind(palindrome *pal);
void init_struct(palindrome *pal, char **av, int ac);
void infinadd(char *string, int nbr, int base);
int palindromic(palindrome *pal);
int print_result(int nb, palindrome *pal, int p, int origin);
int reverse_nbr(int nb, palindrome *pal);

#endif // !__PALINDROME__