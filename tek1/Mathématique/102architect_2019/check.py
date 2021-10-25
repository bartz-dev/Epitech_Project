#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## 102architect_2019
## File description:
## check.py
##

import sys
from calcul import *

def check_error(list):
    i = 1
    while i < len(sys.argv):
        if sys.argv[i] == "-r" or sys.argv[i] == "-s":
            if sys.argv[i - 2].isalpha() or sys.argv[i - 1].isalpha() or sys.argv[i + 1].isalpha():
                print("error")
                sys.exit(84)
            if (len(sys.argv) != (i + 2) and (sys.argv[i + 2] != "-t" !=
             sys.argv[i + 2] != "-s" != sys.argv[i + 2] != "-r" != sys.argv[i + 2] != "-z" )):
                print("error too many arguments")
                sys.exit(84)
        elif sys.argv[i] == "-t" or  sys.argv[i] == "-z":
            if len(sys.argv) != (i + 3):
                print("error too many arguments 2")
                sys.exit(84)
            if (sys.argv[i - 2].isalpha() or sys.argv[i - 1].isalpha() or
             sys.argv[i + 1].isalpha() or sys.argv[i + 2].isalpha()) and (sys.argv[i - 2] != "-t" !=
             sys.argv[i - 2] != "-s" != sys.argv[i - 2] != "-r" != sys.argv[i - 2] != "-z" ):
                print("error")
                sys.exit(84)
        i = i + 1

def check_type(i, list):
    if list[i] == "-r":
        print("Rotation by a", list[i + 1], "degree angle")
        rotate(list[i - 2], list[i - 1], list[i + 1])
    if list[i] == "-t":
        print("Translation along vector ", end="")
        print("(", list[i + 1], ", ", list[i + 2], ")", sep="")
        translat(list[i - 2], list[i - 1], list[i + 1], list[i + 2])
    if list[i] == "-z":
        print("scaling by factors",list[i + 1] ,"and",list[i + 2])
        scaling(list[i - 2], list[i - 1], list[i + 1], list[i + 2])
    if list[i] == "-s":
        print("reflection over the axis passing through 0 with an", end="")
        print(" inclination angle of ", list[i + 1], " degrees", sep="")
        reflection(list[i - 2], list[i - 1], list[i + 1])
        
def help():
    print("USAGE")
    print("    ./102architect X Y transfo1 arg11 [arg12] ", end="")
    print("[transfo arg12 [arg22]] ...\n")
    print("DESCRIPTION")
    print("    X   abscissa of the original point")
    print("    Y   ordinate of the original point\n")
    print("    transfo arg1 [arg2]")
    print("    -t i j  translation along vector(i, j)")
    print("    -z m n  scaling by factors m(x-axis) and n (y_axis)")
    print("    -r d    rotation centered in 0 by a d degree angle")
    print("    -s d    reflection over the axis passing throught 0 ", end="")
    print("with and inclination\n            angle of degrees")