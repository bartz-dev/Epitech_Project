##
## EPITECH PROJECT, 2020
## B-MAT-400-LYN-4-1-202unsold-arthur1.perrot
## File description:
## math.py
##

import sys
from expected_var import expected_variance_display
from z_law import Z_law

def getTotal(list):
    res = 0.0

    for x in list:
        res += x
    return res

def print_my_list(str, list):
    print(str, end="")
    for value in list:
        print("\t%.3f" % value, end="")

def calculate_result(a, b):
    xLaw = [0, 0, 0, 0, 0, 0]
    yLaw = [0, 0, 0, 0, 0, 0]
    ResValues = [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    res = 0.0
    ypos = 0
    xpos = 0

    print("\tX=10\tX=20\tX=30\tX=40\tX=50\tY law")
    for y in [10, 20, 30, 40, 50]:
        xpos = 0
        print("Y=",y, "\t", end="", sep="")
        for x in [10, 20, 30, 40, 50]:
            res = ((a - x) * (b - y))/((5 * a - 150) * (5 * b - 150))
            yLaw[ypos] += res
            xLaw[xpos] += res
            print("%.3f\t" % res, end="")
            xpos = xpos + 1
            ResValues[int((ypos))][int((xpos - 1))] = round(res, 3)

        print("%.3f" % yLaw[ypos])
        ypos = ypos + 1
    xLaw[-1] = getTotal(yLaw)
    print_my_list("X law", xLaw)
    print('')
    print('-' * 80)
    Z_law(ResValues, xLaw, yLaw)
    print('-' * 80)
    expected_variance_display(ResValues, xLaw, yLaw)
    print('-' * 80)