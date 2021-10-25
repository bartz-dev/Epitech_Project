##
## EPITECH PROJECT, 2019
## 108trigo_2019
## File description:
## main.py
##

import sys
from arguments import *
from mymath import *

def main():
    matrix = []
    check_arg()
    sqi = error_handling()
    matrix = addingmatrix(sqi, matrix)
    matrix = launch(matrix)
    print_matrix(matrix)