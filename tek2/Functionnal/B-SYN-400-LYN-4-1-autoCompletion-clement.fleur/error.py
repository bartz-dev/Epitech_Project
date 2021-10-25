##
## EPITECH PROJECT, 2021
## B-SYN-400-LYN-4-1-autoCompletion-clement.fleur [WSL: Ubuntu]
## File description:
## error.py
##

import os, sys

def is_file_empty(filepath):
    # Check if file exist and it is empty
    return os.path.exists(filepath) and os.stat(filepath).st_size == 0

def check_file(filepath):
    if (is_file_empty(filepath)):
        error_print(84, "Invalid argument\n")
    try:
        file = open(filepath, 'r')
    except FileNotFoundError:
        error_print(84, "Invalid argument\n")
    if file.readable == False:
        error_print(84, "Invalid argument")

def error_print(code, message):
    sys.stderr.write(message)
    exit(code)
