/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** pushswap.h
*/

#ifndef pushswap_
#define pushswap_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct req {
	int *list_a;
	int *list_b;
	int sorted_a;
	int sorted_b;
	int len;
	int stat;
};


void check(int ac, char **as, struct req *req);
void serial(int ac, char **as, struct req *req);
void process(struct req *req);
void display_order(struct req *req);
void clean(struct req *req);
struct req* get_request();
void my_put_char(char c);
void my_put_str(const char *str);
void my_put_nbr(int nbr);
void my_put_array(int len, int *arr);
void swap(int *arr, char c, struct req *req);
void push(int *arr, int *arr2, struct req *req, char c);
int remove_first(int *arr, int len);
void add_to(int *arr, int value, int order, int len);
void rotate(int *arr, struct req *req, char c);
int list_sorted(struct req *req);
int get_last(int *arr, int len);
void end_instruction(struct req *req);
int my_strcmp(const char *s1, const char *s2);
int my_atoi(char *str);
int my_str_isnum(const char *str);

#endif
