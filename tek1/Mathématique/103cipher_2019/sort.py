##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## sort.py
##

import sys

def sort_message(com, maxi):
    maxi2 = len(com)/maxi
    if maxi - int(maxi) != 0:
        maxi += 1
        maxi = int(maxi)
    matrix2 = []
    c = 0
    d = 0
    i = 0
    while c < maxi2:
        matrix2.append([])
        while d < maxi:
            if i >= len(com):
                matrix2[c].append(0)
            else:
                matrix2[c].append(ord(com[i]))
            d += 1
            i += 1
        d = 0
        c += 1
    return (matrix2)


def suite(list, maxi):
    maxi2 = len(list)/maxi
    if maxi - int(maxi) != 0:
        maxi += 1
        maxi = int(maxi)
    matrix2 = []
    c = 0
    d = 0
    i = 0
    while c < maxi2:
        matrix2.append([])
        while d < maxi:
            if i >= len(list):
                matrix2[c].append(0)
            else:
                matrix2[c].append(list[i])
            d += 1
            i += 1
        d = 0
        c += 1
    return (matrix2)


def s_message2(com, maxi):
    
    i = 0
    j = 0
    c = 0
    input1 = []
    while i < len(com):
        if com[i] == ' ':
            input1.append(int(com[i - c:i]))
            j += 1
            i += 1
            c = 0
        else:
            i += 1
            c += 1
    input1.append(int(com[i - c:i]))
    return (suite(input1, maxi))