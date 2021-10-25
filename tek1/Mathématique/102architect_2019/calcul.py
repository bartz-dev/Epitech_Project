#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## 102architect_2019
## File description:
## calcul.py
##

import math

def display_one(a, b, c, d, e, f, g, h, x, y):
    a = format(float(a), ".2f")
    b = format(float(b), ".2f")
    c = format(float(c), ".2f")
    d = format(float(d), ".2f")
    e = format(float(e), ".2f")
    f = format(float(f), ".2f")
    g = format(float(g), ".2f")
    h = format(float(h), ".2f")
    print(a, "   ", b, "   ", c)
    print(d, "   ", e, "   ", f)
    print("0.00    0.00    1.00")
    print("(", x ,", ", y, ") => (", g, ", ", h, ")", sep="")

def rotate(x, y, d):
    d = float(d)
    x = float(x)
    y = float(y)
    d = d * math.pi / 180
    a = math.cos(d)
    b = 0 - math.sin(d)
    c = math.sin(d)
    e = math.sin(d)
    display_one(a, b, 0, c, e, 0, y, x, x, y)

def reflection(x, y, angle):
    y = float (y)
    x = float (x)
    angle = float (angle)
    angle = angle * math.pi / 180
    print(format(math.cos(angle*2), ".2f"), "  ", format(math.sin(angle*2), ".2f"),"   ", "0.00")
    print(format(math.sin(2*angle), ".2f"),"  ", format(-math.cos(2 * angle), ".2f"),"  ", "0.00")
    print("0.00   ", "0,00   ", format(y * (-1), ".2f"))
    print("(",format(x ,".2f"),", ",format(y,".2f"),end ="",sep="")
    print(") => (", format(math.sin(angle)*x+math.cos(angle)*y, ".2f"),", ", end="",sep="")
    print(format(math.cos(angle)*x-math.sin(angle)*y, ".2f"), ")", sep="")

def scaling(x, y , i , j):
    print(format(float (i), ".2f"), "  0.00   ", "0.00")
    print("0.00   ", format(float (j), ".2f"),"  ", "0.00")
    print("0.00   ", "0,00   ", format(float (j), ".2f"))
    print("(",format(float(x),".2f"),", ",format(float(y),".2f"),end="",sep="")
    print(") => (", format(float(x) * float(i), ".2f"),", ", end="",sep="")
    print(format(float (y) * float (j), ".2f"), ")", sep="")

def translat(x, y, i, j):
    print(format(float (j), ".2f"), "   0.00   ", format(float (i), ".2f"))
    print("0.00   ", format(float (j), ".2f"),"  ", format(float (j), ".2f"))
    print("0.00   ", "0,00   ", "1.00")
    print("(",format(float(x),".2f"),", ",format(float(y),".2f"),end="",sep="")
    print(") => (", format(float(x) + float(i), ".2f"),", ", end="",sep="")
    print(format(float (y) + float (j), ".2f"), ")", sep="")