##
## EPITECH PROJECT, 2020
## B-MAT-400-LYN-4-1-205IQ-arthur1.perrot
## File description:
## mat
##

import sys
from math import *

class Gaussian:
    def __init__(self):
        self.u = 0.0
        self.s = 0.0
        self.fstIQ = 0
        self.lastIQ = 0
        self.res = 0.0

    def sma(self):
        i = 0

        while (i < 201):
            self.res = (1 / ((self.s) * sqrt(2 * pi))) * exp(-0.5 * pow((self.u - i) / self.s, 2))
            print(i, "%.5f" % self.res)
            i += 1

    def calculPercentage(self):
        i = self.fstIQ
        while (i < self.lastIQ):
            self.res = self.res + (1 / ((self.s) * sqrt(2 * pi))) * exp(-0.5 * pow((self.u - float(i)) / self.s, 2))
            i += 0.01
        print("%.1f" % (self.res), end="")

    def init(self):
        self.u = float(sys.argv[1])
        self.s = float(sys.argv[2])
        if len(sys.argv) > 4:
            self.fstIQ = int(sys.argv[3])
            self.lastIQ = int(sys.argv[4])
            self.calculPercentage()
            print ("% of people have an IQ between ", self.fstIQ," and ", self.lastIQ, sep="")
        elif len(sys.argv) == 4:
            self.lastIQ = int(sys.argv[3])
            self.calculPercentage()
            print ("% of people have an IQ inferior to ", self.lastIQ, sep="")
        else:
            self.sma()