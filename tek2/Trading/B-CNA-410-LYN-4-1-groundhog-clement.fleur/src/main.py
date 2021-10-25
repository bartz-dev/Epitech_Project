#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## B-CNA-410-LYN-4-1-groundhog-clement.fleur
## File description:
## main.py
##

from src.groundhog import Groundhog

import sys

def printHelp():
    print("SYNOPSIS")
    print("    ./groundhog period")
    print("")
    print("DESCRIPTION")
    print("    period\t  the number of days defining a period")

def errorHandling():
    if len(sys.argv) != 2:
        return 84;
    elif sys.argv[1] == "-h":
        printHelp();
        exit(0)
    return 0;


def main():
    if errorHandling() == 84:
        exit(84);
    groundhog = Groundhog();
    groundhog.init();


if __name__ == '__main__':
    main()
