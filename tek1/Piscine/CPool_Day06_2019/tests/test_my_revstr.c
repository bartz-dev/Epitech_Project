/*
** EPITECH PROJECT, 2019
** test_my_revstr
** File description:
** test for my_revstr
*/
#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, reverse_five_characters_in_empty_array)
{
    cr_assert_str_eq(my_revstr(strdup("Hello")), "olleH");
}
