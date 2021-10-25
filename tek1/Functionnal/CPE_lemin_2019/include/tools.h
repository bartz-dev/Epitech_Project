/*
** EPITECH PROJECT, 2019
** libtools
** File description:
** Global library for epitech studies
*/

#ifndef LIBTOOLS
#define LIBTOOLS
#define my_abs(nb) ((nb < 0) ? -(nb) : (nb))
#define square(nb) ((nb) * (nb))
#define distance(a, b) my_abs(sqrt(square(a.x - b.x) + square(a.y - b.y)))
#define UNUSED(x) ((x) = (x))

typedef struct counter {
    int i;
    int j;
} counter_t;

#define UNDEFINED 0

typedef struct vector2i {
    int x;
    int y;
} vector2i_t;

typedef struct vector2f {
    float x;
    float y;
} vector2f_t;

typedef struct vector3i {
    int x;
    int y;
    int z;
} vector3i_t;

typedef struct vector3f {
    float x;
    float y;
    float z;
} vector3f_t;

int my_putchar(char c);
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
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
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
int my_putdouble(double d, int decimals, int remove_zeros);
int get_number_of_digits(int nb);
int max(int nb1, int nb2);
int min(int nb1, int nb2);
char **my_strsplit(char *str, char c);
char **my_strslice(char *str, int i);
char *my_strconcat(char const *str1, char const *str2);
char *my_int_to_str(int nb);
int my_xor(int cond1, int cond2);
int my_printf(char const *format, ...);
int my_put_nbrp(int *nb);
int my_putcharp(char *c);
int my_putfloatp(float *f, int decimals);
int my_putdoublep(double *d, int decimals);
vector2i_t v2i(int x, int y);
vector2f_t v2f(float x, float y);
vector3i_t v3i(int x, int y, int z);
vector3f_t v3f(float x, float y, float z);
int my_str_startswith(char *haystack, char *needle);
int *pint(int i);
double *pdouble(double i);
char *read_file(char *filepath);
int is_whitespace(char c);
char *my_strtrimwhitesp(char *str);
char *my_trim_keep_str(char *str);
void *my_free_assign(void *to_free, void *value);
char *my_char_to_str(char c);
char *stripslashes(char *str);
char *addslashes(char *str);
int my_strncmp(char *s1, char *s2, int n);
int my_str_isnum(char const *str);
int my_str_endswith(char *str, char *with);
int irand(int min, int max);
double sqrt(double nb);
int is_whitespace(char c);
char *my_strjoin(char **arr, char *glue);
void free_split(char **split);

#endif