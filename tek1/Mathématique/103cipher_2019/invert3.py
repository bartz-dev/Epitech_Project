##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## invert3.py
##

import sys

def check(matrix):
    i = 0
    j = 0
    while i < 3:
        while j < 3:
            if matrix[i][j] < 0.001 and matrix[i][j] > -0.001:
                matrix[i][j] = 0.0
            j += 1
        j = 0
        i += 1
    return(matrix)


def inversion_matrice(matrix):
    d = matrix[0][0] * matrix[1][1] * matrix[2][2]
    d += matrix[0][1] * matrix[1][2] * matrix[2][0]
    d += matrix[0][2] * matrix[1][0] * matrix[2][1]
    d -= matrix[0][2] * matrix[1][1] * matrix[2][0]
    d -= matrix[0][0] * matrix[1][2] * matrix[2][1]
    d -= matrix[0][1] * matrix[1][0] * matrix[2][2]
    d = 1 / d
    matrix2 = [[]]
    matrix2[0].append(d * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]))
    matrix2[0].append(d * (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]))
    matrix2[0].append(d * (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]))

    matrix2.append([])

    matrix2[1].append(d * (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]))
    matrix2[1].append(d * (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]))
    matrix2[1].append(d * (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]))

    matrix2.append([])

    matrix2[2].append(d * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]))
    matrix2[2].append(d * (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]))  
    matrix2[2].append(d * (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]))
    #check(matrix2)
    print(str(round(matrix2[0][0], 3)) + "\t" + str(round(matrix2[0][1], 3)) + "\t" + str(round(matrix2[0][2], 3)))
    print(str(round(matrix2[1][0], 3)) + "\t" + str(round(matrix2[1][1], 3)) + "\t" + str(round(matrix2[1][2], 3)))
    print(str(round(matrix2[2][0], 3)) + "\t" + str(round(matrix2[2][1], 3)) + "\t" + str(round(matrix2[2][2], 3)))
    return (matrix2)