##
## EPITECH PROJECT, 2021
## B-SYN-400-LYN-4-1-autoCompletion-clement.fleur [WSL: Ubuntu]
## File description:
## utils.py
##

def has_number(str):
    return any(char.isdigit() for char in str)

def get_digit(str):
    c = ""

    for i in str:
        if i.isdigit():
            c += i
    return c

def find_digit_pos(str):
    return str.find(get_digit(str))