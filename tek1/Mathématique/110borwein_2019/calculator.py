#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## 110borwein_2019
## File description:
## calculator.py
##

import math

def call_all_functions(n):
    h = float(5000) / 10000
    a = 0
    b  = 5000

    print("Midpoint:")
    midpoint(n, h, a, b, 0)
    print("\nTrapezoidal:")
    trapezoidal(n, h, a, b, 0)
    print("\nSimpson:")
    simpson(n, h, a, b, 0)

def borwein(n, x):
    result = 1.0
    k = 0

    while k <= n:
        if x != 0:
            result = result * (math.sin(x / ((2 * k) + 1)) / (x / ((2 * k)+ 1)))
        k = k + 1
    return result

def midpoint(n, h, a, b, result):
    i = 0
    res = 0.0

    for i in range(1, 10000 + 1):
        res += h * borwein(n, a - (0.5 * h) + (i * h))
    p = res - (math.pi / 2)
    if p < 0:
        p = p * (-1)
    print ("I{:.0f} = {:.10f}".format(n, res))
    print ("diff = {:.10f}".format(p))
    return 0

def trapezoidal(n, h, a, b, result):
    i = float(1)

    while (i < 10000):
        x = i * h
        result += borwein(n, x)
        i = i + 1
    result = ((result * 2) + borwein(n, a) + borwein(n, b))
    calc = result * h / 2
    p = calc - (math.pi / 2)
    if p < 0:
        p = p * (-1)
    print ("I{:.0f} = {:.10f}".format(n, calc))
    p = round(p, 10)
    if (p == -0):
        print("diff = 0.0000000000")
    else:
        print ("diff = {:.10f}".format(p))

def simpson(n, h, a, b, result):
    i = 0

    while (i < 10000):
        x = i * h
        if (i == 0):
            result += 4 * borwein(n, x + (h / 2))
        else:
            result += (2 * borwein(n, x)) + (4 * borwein(n, x + (h / 2)))
        i += 1
    result = (borwein(n, a) + borwein(n, b) + result) * h / 6
    p = result - (math.pi / 2)
    if p < 0:
        p = p * (-1)
    print ("I{:.0f} = {:.10f}".format(n,result))
    p = round(p, 10)
    if (p == -0):
        print("diff = 0.0000000000")
    else:
        print ("diff = {:.10f}".format(p))