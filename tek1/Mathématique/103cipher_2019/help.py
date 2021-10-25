##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## man -h
##

import sys

def help_h():
    print("USAGE")
    print("    ./103cipher message key flag\n")
    print("DESCRIPTION")
    print("    message     a message, made of ASCII characters")
    print("    key         the encryption key, made of ASCII characters")
    sys.exit(0)
