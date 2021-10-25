#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## 108trigo_201
## File description:
## maths.py
##

import sys
import math

def growth_rate():
    try:
        x = float(sys.argv[1])
        k = float(sys.argv[2])
        x1 = x
        i = 1
    except ValueError:
        print ("Please check your arguments, or see -h")
        sys.exit(84)

    if (k > 4) or (k < 1):
        print ("Error: k must be between 1 and 4")
        print ("Please see -h")
        sys.exit(84)
    while i <= 100:
        print(i, " ", format(x1, ".2f"), sep="")
        x1 = k * x * ((1000 - x )/ 1000)
        x = x1
        i = i + 1

def my_exp():
    print("exp")

def my_cos():
    print("cos")

def my_sin():
    print("sin")

def my_cosh():
    print("cosh")

def my_sinh():
    print("sinh")