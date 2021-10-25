##
## EPITECH PROJECT, 2020
## B-MAT-400-LYN-4-1-202unsold-arthur1.perrot [WSL: Debian]
## File description:
## z_law.py
##

import sys

def PopZ():
    z_tab = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    argA = int(sys.argv[1])
    argB = int(sys.argv[2])

    for z in range (20, 101, 10):
            for y in range (10, 51, 10):
                for x in range (10, 51, 10):
                    if (x+y) == z and y < 60:
                        z_tab[int(z / 10) - 2] += ((argA - x) * (argB - y)) / ((5 * argA - 150) * (5 * argB - 150))
    return z_tab

def Z_law(ResValues, xLaw, yLaw):
    print("z\t20\t30\t40\t50\t60\t70\t80\t90\t100")
    print("p(Z=z)", end="")
    z_tab = PopZ()
    for value in z_tab:
        print("\t%0.3f" % value, end='')
    print("")