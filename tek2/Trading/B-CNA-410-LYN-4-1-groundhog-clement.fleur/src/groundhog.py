##
## EPITECH PROJECT, 2020
## B-CNA-410-LYN-4-1-groundhog-clement.fleur
## File description:
## groundhog
##

import sys
from math import *

class Groundhog:
    def __init__(self):
        self.period = 0
        self.values = list()
        self.last = 0.0
        self.avgTempIncrease = 0.0
        self.rltTempEvolution = 0.0
        self.stdDeviation = 0.0
        self.switchoccurs = False
        self.nbswitch = 0

    def construct(self):
        try:
            self.period = int(sys.argv[1])
        except:
            print("Error you must enter value !")
            exit(84)

    def averageTempIncrease(self):
        self.avgTempIncrease = 0.0
        next = ((len(self.values) - self.period) - 1)
        res = 0

        if next <= 0: next = 1
        for i in range (next, len(self.values)):
            if (next != len(self.values)):
                res = self.values[i] - self.values[i - 1]
                if res > 0:
                    self.avgTempIncrease += res
            next += 1
        self.avgTempIncrease = ((self.avgTempIncrease/self.period))
        try:
            self.avgTempIncrease /= self.period
        except ZeroDivisionError:
            self.avgTempIncrease = 0
        print("g=%.2f\t" % self.avgTempIncrease, end="")

    def relativeTempEvolution(self):
        res = 0.0

        res = ((self.values[-1] - self.values[0])/self.values[0])*100
        print("\tr=%.f" % res, "%\t", sep="", end="")
        if (res > 0 and self.rltTempEvolution < 0) or (res < 0 and self.rltTempEvolution > 0):
            self.switchoccurs = True
            self.nbswitch += 1
        self.rltTempEvolution = res

    def standardDeviation(self):
        res = 0.0
        u = 0.0

        for r in range(len(self.values) - self.period, len(self.values)):
            u += self.values[r]
        u /= self.period
        for x in range(len(self.values) - self.period, len(self.values)):
            res += pow(self.values[x] - u, 2)
        self.stdDeviation = sqrt(res/self.period)
        if self.rltTempEvolution == 0.0:
            print("\t", end="")
        print("\ts=%.2f" % self.stdDeviation, end="")
        if (self.switchoccurs):
            print("\t\ta switch occurs")
            self.switchoccurs = False
        else:
            print("\n", end="")



    def technicalIndicators(self, input):
        if (len(self.values) - 1 >= self.period):
            self.values.pop(0)
        self.values.append(input)
        if len(self.values) > self.period:
            self.averageTempIncrease()
            self.relativeTempEvolution()
        else:
            print("g=nan", end="")
            sys.stdout.write("\t\tr=nan")
        if len(self.values) > self.period - 1:
            self.standardDeviation()
        else:
            print("\t\ts=nan")

    def weirdestValues(self):
        print("ok")

    def loop(self):
        while(1):
            try:
                user_input = input()
            except (EOFError, KeyError, KeyboardInterrupt) as error:
                exit(84);
            if user_input == "STOP":
                print("Global tendency switched %d times" % self.nbswitch)
                exit(0)
            else:
                try:
                    user_input = float(user_input)
                except:
                    print("error you enter wrong value !")
                    exit(84)
                self.technicalIndicators(user_input)

    def init(self):
        self.construct()
        self.loop()