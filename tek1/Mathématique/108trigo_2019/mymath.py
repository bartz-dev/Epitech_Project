##
## EPITECH PROJECT, 2019
## 108trigo_2019
## File description:
## mymath.py
##

import math, sys
from matrix import *

def launch(matrix):
    args = ["EXP", "COS", "SIN", "COSH", "SINH"]
    fct_tab = [my_exp, my_cos, my_sin, my_cosh, my_sinh]
    for i in range(len(fct_tab)):
        if sys.argv[1] == args[i]:
            matrix = fct_tab[i](matrix)
    return matrix

def my_exp(matrix):
    tmp = identity_mat(len(matrix))
    for i in range(1, 50):
        tmp = add_mat(tmp, div_mat(pow_mat(matrix, i), math.factorial(i)))
    return tmp

def my_cos(matrix):
    tmp = identity_mat(len(matrix))
    for i in range(1, 40):
        if i % 2 == 0:
            tmp = add_mat(tmp, div_mat(pow_mat(matrix, 2 * i), math.factorial(2 * i)))
        else:
            tmp = sub_mat(tmp, div_mat(pow_mat(matrix, 2 * i), math.factorial(2 * i)))
    return tmp

def my_sin(matrix):
    tmp = matrix
    for i in range(1, 40):
        if i % 2 == 0:
            tmp = add_mat(tmp, div_mat(pow_mat(matrix, 2 * i + 1), math.factorial(2 * i + 1)))
        else:
            tmp = sub_mat(tmp, div_mat(pow_mat(matrix, 2 * i + 1), math.factorial(2 * i + 1)))
    return tmp

def my_cosh(matrix):
    tmp = identity_mat(len(matrix))
    for i in range(1, 40):
        tmp = add_mat(tmp, div_mat(pow_mat(matrix, 2 * i), math.factorial(2 * i)))
    return tmp

def my_sinh(matrix):
    tmp = matrix
    for i in range(1, 40):
        tmp = add_mat(tmp, div_mat(pow_mat(matrix, 2 * i + 1), math.factorial(2 * i + 1)))
    return tmp