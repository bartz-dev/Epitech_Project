#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## B-SYN-400-LYN-4-1-autoCompletion-clement.fleur [WSL: Ubuntu]
## File description:
## autoCompletion.py
##

import sys
from autoCompletion import *
from error import error_print

def printHelp():
    print("USAGE\n\t./autoCompletion dictionary\n")
    print("DESCRIPTION\n\tdictionary\tfile containing one adress per line, as knowledge base")

def main():
    if (len(sys.argv) > 1 and sys.argv[1] == "-h"):
        printHelp()
    elif (len(sys.argv) == 2):
        #launch autocompletion
        try:
            completion = autoCompletion()
            completion.run(sys.argv[1])
        except (EOFError, KeyboardInterrupt):
            exit(84)
    else:
        error_print(84, "Invalid argument\n")

if __name__ == '__main__':
    main()