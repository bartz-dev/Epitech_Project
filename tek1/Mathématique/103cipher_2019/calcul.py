##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## calcul/write matrix
##

import math

def check_value(value, value2):
    if format(value) == 0:
        print(round(value*(-1), 3),"\t", end="")
    else:
        print(round(value, 3),"\t", end="")
    if format(value2) == 0:
        print(round(value*(-1), 3))
    else:
        print(round(value, 3))

def reverse_bytwo(matrix):
    matrix[0][1] *= (-1)
    matrix[1][0] *= (-1)
    x = matrix[0][0]
    matrix[0][0] = matrix[1][1]
    matrix[1][1] = x
    ad = matrix[0][0]*matrix[1][1]
    bc = matrix[0][1]*(-1)*matrix[1][0]*(-1)
    a = 1/(ad-bc)
    matrix[0][0] = a * matrix[0][0]
    matrix[0][1] = a * matrix[0][1]
    check_value(matrix[0][0], matrix[0][1])
    matrix[1][0] = a * matrix[1][0]
    matrix[1][1] = a * matrix[1][1]
    check_value(matrix[1][0], matrix[1][1])
    return (matrix)

    
def print_matrix(matrix, max):
    p = 0
    i = 0

    while i <= max:
        if i == max and p != max:
            p = p + 1
            i = 0
        if i == max or p == max:
            i = max + 1
        elif i == max - 1:
            print(matrix[p][i])
        else:
            print(matrix[p][i],"\t", end="")
        i = i + 1

def matrice(word):
    i = 0
    print("Key matrix:")
    while math.sqrt(len(word)) > i:
        i += 1
    matrix = []
    c = 0
    d = 0
    maxi = i
    i = 0
    while c < maxi:
        matrix.append([])
        while d < maxi:
            if i >= len(word):
                matrix[c].append(0)
            else:
                matrix[c].append(ord(word[i]))
            d += 1
            i += 1
        d = 0
        c += 1
    return (matrix)
