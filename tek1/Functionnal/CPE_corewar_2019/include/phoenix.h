/*
** EPITECH PROJECT, 2019
** folder
** File description:
** my.h
*/

int is_prime_number(int nb);
void my_putchar (char c);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr (char *str, char const *to_find);
char * my_revstr(char *str);
int my_putnbr (int nb);
int my_putstr(char const *str);
int to_number(char const *str);
char *concat_strings (char *dest, char const *src);
int sorted_params (int ac, char **av);
int show_params (int ac, char **av);
int my_getnbr (char const *str);
//Lists
typedef struct Element Element;
struct Element
{
    int number;
    Element *next;
};

typedef struct List List;
struct List
{
    Element *first;
};
List *init_list(void);
int add_first_element(List *list, int new_number);
int delete_element(List *list);
int display_list(List *list);
