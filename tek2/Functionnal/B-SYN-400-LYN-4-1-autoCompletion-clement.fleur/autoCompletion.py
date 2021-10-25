##
## EPITECH PROJECT, 2021
## B-SYN-400-LYN-4-1-autoCompletion-clement.fleur [WSL: Ubuntu]
## File description:
## autoCompletion.py
##

from error import *
from utils import *
from algorithm import *
from matcher import *

class autoCompletion:
    def __init__(self):
        self.data = list()
        self.result = list()
        self.mp = list()
        self.city = None
        self.enginesort = []

    def iterate(self):
        value = input()

        while (value != "ABORT"):
            if (len(value) > 1 and value != "ABORT"):
                error_print(84, "Invalid argument\n")
            self.find_city(value)
            value = input()
            # RESULT

    def find_most_probable_city(self, elem, index):
        checked = False

        for rhs in self.mp:
            if rhs.key.lower() == elem[index][0].lower():
                checked = True
                rhs.value = rhs.value + 1
            
        if checked == False:
            self.mp.append(choice(1, elem[index][0].lower()))

        if (index < len(elem) - 1):
            self.find_most_probable_city(elem, index + 1)
        
    def find_city(self, value):
        checked = 0
    
        if (len(self.enginesort) > 1):
            for elem in self.enginesort:
                if elem[len(elem) - 1].lower() == value.lower():
                    checked = 1
                    self.city.setkey(self.city.key + value)
                    self.enginesort = self.city.find_occurence(self.data)
                    break
        elif (len(self.mp) > 0 and len(self.enginesort) == 0):
            for elem in self.mp:
                if elem.key[len(elem.key) - 1].lower() == value.lower():
                    checked = 1
                    self.city = matcher(elem.key)
                    self.enginesort = self.city.find_occurence(self.data)
        if len(self.enginesort) == 1:
            self.city.setkey(self.enginesort[0])
            checked = 1
        if checked == 0:
            error_print(84, "Invalid argument\n")

    def check_upper_order(self, tmp, mp):
        tmp.sort(key=lambda x: ord(x.key))

        return tmp
            
    def run(self, filepath):
        check_file(filepath)
        file = open(filepath, 'r')
        for elem in file.readlines():
            elem = adress_validity(elem)
            set = elem.find(',')
            self.data.append(adress(elem[:set], elem[set + 1:]))

        self.data = remove_duplication(self.data)
        for elem in self.data:
            self.find_most_probable_city(elem.city.split(), 0)
        self.sort_choice()
        print_list(self.mp[:5])
        
        self.iterate()
        file.close()

    def sort_choice(self):
        tmp = self.mp
        tmp = self.check_upper_order(tmp, self.mp)
        self.mp.sort(key=lambda x: int(x.value), reverse=True)

    def already_in(self, key):
        for elem in self.mp:
            if elem.city == key:
                return True
        return False
    
    def getcity(self):
        return self.city

def remove_duplication(object):
    new_dict = {}
    return [new_dict.setdefault(x, x) for x in object if x not in new_dict]

def replace_misplaced_number(elem, streetT):
    if (find_digit_pos(elem) > elem.find(streetT)):
        tmp = get_digit(elem)
        elem = elem[:elem.find(streetT)] + tmp + ' ' + elem[elem.find(streetT):find_digit_pos(elem) - 1]
    return elem

def replace_misplaced_city(elem):
    if (find_digit_pos(elem) < elem.find(',')):
        elem = elem[elem.find(',') + 2:].strip() + ", " + elem[:elem.find(',')]
    return elem

def adress_validity(elem):
    comma = elem.find(',')
    checked = 0

    for rhs in streettype:
        if elem.find(rhs) != -1:
            tmp = rhs
            checked = 1
            break
    if checked == 0:
        error_print(84, elem + "Unknown address\n")
    elem = replace_misplaced_number(elem, tmp)
    if (comma == -1):
        elem =  elem[:elem.find(get_digit(elem)) - 1] + ', ' + elem[elem.find(get_digit(elem)):]
        comma = elem.find(',')
    if any(map(str.isdigit, elem)) == False:
        error_print(84, elem + "Unknown address\n")
    elem = replace_misplaced_city(elem)
    elem = elem.strip()
    return elem

def print_list(myList):
    count = 0
    for elem in myList:
        count = count + 1
        print('{' + elem.key.lower() + '}', end="")
        if count < len(myList):
            print(' ', end="")
    print("\n", end="")

