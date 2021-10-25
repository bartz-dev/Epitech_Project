##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## result.py
##

def calc(matrix, asci):
    result = []
    i = 0
    j = 0
    x = 0
    c = 0
    nb = 0
    y = 0
    z = 0
    while z < len(asci):
        while j < len(matrix):
            while c < len(matrix):
                nb += matrix[x][i] * asci[y][x]
                x += 1
                c += 1
            if z + 1 == len(asci) and j + 1 == len(matrix):
                print(nb)
            else:
                print(nb, "", end="")
            result.append(nb)
            i +=1
            c = 0
            j += 1
            x = 0
            nb = 0
        i = 0
        j = 0
        y += 1
        z += 1


def calc2(matrix, asci):
    result = []
    i = 0
    j = 0
    x = 0
    c = 0
    nb = 0
    y = 0
    z = 0
    while z < len(asci):
        while j < len(matrix):
            while c < len(matrix):
                nb += matrix[x][i] * asci[y][x]
                x += 1
                c += 1
            if z + 1 == len(asci) and j + 1 == len(matrix):
                print(chr(int(round(nb, 1))))
            else:
                print(chr(int(round(nb, 1))), end="")
            result.append(nb)
            i +=1
            c = 0
            j += 1
            x = 0
            nb = 0
        i = 0
        j = 0
        y += 1
        z += 1

def calc3(matrix, asci):
    result = []
    i = 0
    j = 0
    x = 0
    c = 0
    nb = 0
    y = 0
    z = 0
    while j < len(matrix):
        while c < len(matrix):
            nb += matrix[x][i] * asci[y][x]
            x += 1
            c += 1
        if j + 1 == len(matrix):
            print(chr(int(round(nb, 1))))
        else:
            print(chr(int(round(nb, 1))), end="")
        result.append(nb)
        i +=1
        c = 0
        j += 1
        x = 0
        nb = 0
        y =+ 1