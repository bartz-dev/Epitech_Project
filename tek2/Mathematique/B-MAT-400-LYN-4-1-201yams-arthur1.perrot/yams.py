##
## EPITECH PROJECT, 2020
## B-MAT-400-LYN-4-1-201yams-arthur1.perrot
## File description:
## yams.py
##

import math

def pair(value, arg):
    print("Chances to get a %s pair: %.2f%%" % (arg, iterate(2, value, arg)))

def three(value, arg):
    print("Chances to get a %s three-of-a-kind: %.2f%%" % (arg, iterate(3, value, arg)))

def four(value, arg):
    print("Chances to get a %s four-of-a-kind: %.2f%%" % (arg, iterate(4, value, arg)))

def yams(value, arg):
    print("Chances to get a %s yams: %.2f%%" % (arg, iterate(5, value, arg)))

def full(value, arg):
    print("full")

def straight(value, arg):
    print("straight")

def binomiale(a, b):
    res = (math.factorial(a) / (math.factorial(b) * math.factorial(a-b))) * pow(1/6, b) * pow(5/6, a-b)
    return (res)

def iterate(TypetoFind, args, nbtoFind):
    NbOccurence = args.count(int(nbtoFind))
    result = 0
    if NbOccurence >= TypetoFind:
        return 100
    else:
        for i in range(TypetoFind - NbOccurence, 5 - NbOccurence + 1):
            result += binomiale(5 - NbOccurence, i)
    return result * 100