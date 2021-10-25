##
## EPITECH PROJECT, 2019
## 109titration_2019
## File description:
## arguments.py
##

import math
from result import *

def calculateestimate(list, ph2, ph, length):
    count = 1
    e = findmax(ph, max(ph))
    min = float(list[e - 1][:nlen(list[e - 1])])
    maxi = float(list[e + 1][:nlen(list[e + 1])])
    mid = float(list[e][:nlen(list[e])])
    mathvar = float(min)
    result = []
    result.append(float(ph2[e-1]))

    print(min, "ml ->", "{:.2f}".format(result[0]))
    while ("{:.2f}".format(mathvar) != "{:.2f}".format(mid)):
        mathvar = mathvar + 0.1
        result.append(float(ph2[e-1]+(mathvar-min)*(ph2[e]-ph2[e-1])/(mid-min)))
        print("{:.1f}".format(mathvar),"ml ->", "{:.2f}".format(result[count]))
        count = count + 1
    while ("{:.2f}".format(mathvar) != "{:.2f}".format(maxi)):
        mathvar = mathvar + 0.1
        result.append(float(ph2[e]+(mathvar-mid)*(ph2[e+1]-ph2[e])/(maxi-mid)))
        print("{:.1f}".format(mathvar),"ml ->", "{:.2f}".format(result[count]))
        count = count + 1
    writingresult(result, min, maxi)

def calculate(list, ph, length):
    p = 0
    max = 0
    ph2 = []
    ph2.append(1)
    for i in range(1, length):
        ph2.append(myderive(list, ph, i))
        print("{:.1f}".format(float(list[i][:nlen(list[i])])),end="")
        print(" ml ->", "{:.2f}".format(ph2[i]))
        if ph2[i] > max:
            p = i;
            max = ph2[i]
    print("\nEquivalence point at", format(float(list[p][:nlen(list[p])])),
    "ml") if length == len(list) - 1 else print("\n",
    "Second derivative estimated:", sep="")
    return ph2

def myderive(list, ph, i):
    x =  float(list[i][:nlen(list[i])])
    x1 = float(list[i - 1][:nlen(list[i - 1])])
    x3 = float(list[i + 1][:nlen(list[i + 1])])
    nbr = (ph[i] - ph[i - 1])/(x-x1)*(x3-x)+((ph[i+1]-ph[i])/(x3-x))*(x-x1)
    nbr = nbr/(x3-x1)
    return nbr

def nlen(leno):
    for i in range(0, len(leno)):
        if leno[i] == ';':
            return i

def findmax(ph, maxi):
    i = 0
    while ph[i] != maxi:
        i +=1
    return i