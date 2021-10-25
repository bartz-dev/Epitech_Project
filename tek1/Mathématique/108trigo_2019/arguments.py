##
## EPITECH PROJECT, 2019
## 108trigo_2019
## File description:
## arguments.py
##

import sys
import math
from utils import *

def addingmatrix(sqi, matrix):
    for i in range(int(sqi)):
        matrix.append([])
        for j in range(int(sqi)):
            matrix[i].append(sys.argv[i * int(sqi) + j + 2])
    return matrix

def check_arg():
    if "-h" in sys.argv or "--help" in sys.argv:
        printhelp()
    if len(sys.argv) <= 2 or sys.argv[1] not in ["EXP", "COS", "SIN", "COSH", "SINH"]:
        print("Missing arguments.\nUsage: ./108trigo fun a0 a1 a2 ...", file=sys.stderr)
        exit(84)
    try:
        for i in range(2, len(sys.argv)):
            sys.argv[i] = float(sys.argv[i])
    except ValueError:
        print("Argument %d (%s) isn't a number" % (i, sys.argv[i]), file=sys.sys.stderr)
        exit(84)

def error_handling():
    i = len(sys.argv) - 2
    sqi = math.trunc(math.sqrt(i))
    if math.trunc(math.sqrt(i)) ** 2 != i:
        print("Missing arguments.\nUsage: ./108trigo fun a0 a1 a2 ...", file=sys.stderr)
        exit(84)
    return sqi