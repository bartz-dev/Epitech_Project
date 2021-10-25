##
## EPITECH PROJECT, 2020
## B-MAT-400-LYN-4-1-203hotline-arthur1.perrot
## File description:
## utils.py
##

import math
import time

def binomial_coef(n, k):
    first = math.factorial(n)
    second = math.factorial(k)

    return first//(second * math.factorial(n - k))

def binomial(d):
    res = 0.0
    overload = 0.0
    average = d/(3600*8)
    startTime = time.time()

    for x in range(0, 51):
        if (x != 0 and x % 5 == 0):
            print("\n", end="")
        res = (binomial_coef(3500, x) * average**x)*((1 - average)**(3500 - x))
        print("%d -> %.3f" % (x, res), end="")
        if ((x + 1) % 5 != 0 and x != 50):
            print("\t", end="")
        if x > 25:
            overload += res
    endTime = time.time()
    print("\nOverload: %.1f" % (overload * 100) + '%')
    print("Computation time: %.2f ms\n" % ((endTime - startTime) * 1000))

def poisson(d):
    res = 0.0
    overload = 0.0
    average = 3500 * (d/(3600*8))
    startTime = time.time()

    for x in range(0, 51):
        if (x != 0 and x % 5 == 0):
            print("\n", end="")
        res = math.exp(-average) * (average**x) / math.factorial(x)
        print("%d -> %.3f" % (x, res), end="")
        if ((x + 1) % 5 != 0 and x != 50):
            print("\t", end="")
        if x > 25:
            overload += res
    endTime = time.time()
    print("\nOverload: %.1f" % (overload * 100) + '%')
    print("Computation time: %.2f ms" % ((endTime - startTime) * 1000))