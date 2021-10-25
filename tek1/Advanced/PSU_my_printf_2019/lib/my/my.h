/*
** EPITECH PROJECT, 2019
** mylib
** File description:
** Global library for epitech studies
*/

#ifndef LIBMY
#define LIBMY

struct counter {
    int i;
    int j;
};

typedef struct counter counter_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int nb, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *stc, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *arr);
char *my_strdup(char const *str);
int my_arrlen(char **arr);
int get_number(char c);
int process_letter(unsigned int *nb, int *preceeded_by_minus);
int can_divide_by(int a, int b);
int get_digit(int nb, int n);
int get_power_of_ten(int n);
int is_in(char c, char a, char z);
void add_string_to_arr(char *str, char **arr, int *start, counter_t *count);
void calculate_array_size(char *str, counter_t count, int *size);
char **my_str_to_word_array(char const *str);
int my_putfloat(float f, int decimals);
int my_putdouble(double d, int decimals);
int get_number_of_digits(int nb);
int max(int nb1, int nb2);
char **my_strsplit(char *str, int pos);
char *my_strshift(char *str, int pos);
char *my_strconcat(char const *str1, char const *str2);
char *my_int_to_str(int nb);
char *my_remove_whitespaces(char *str);
char *my_char_to_str(char c);
int xor(int cond1, int cond2);
void my_printf(char *av, ...);

#endif
