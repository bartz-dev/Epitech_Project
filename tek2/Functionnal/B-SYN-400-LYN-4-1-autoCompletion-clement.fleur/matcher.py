##
## EPITECH PROJECT, 2021
## B-SYN-400-LYN-4-1-autoCompletion-clement.fleur [WSL: Ubuntu]
## File description:
## matcher.py
##

class choice:
    def __init__(self, value, key):
        self.value = value
        self.key = key

    def get_value(self):
        return self.value

    def __str__(self) -> str:
        return str(self.value)
    
    def __repr__(self) -> str:
        return str(self.value)

class matcher:
    def __init__(self, key):
        self.seq = None
        self.key = key
        self.mp = list()
        self.adress = list()
        len = int()

    def getnextattribute(self):
        res = []

        self.len = self.nexttofind()
        self.key = self.seq[0][:self.len]
        for elem in self.seq:
            res.append(elem[:self.len + 1].lower())
        return list(set(res))

    def nexttofind(self):
        tmp = ""
        checked = 1
        count = self.len + 1

        for elem in self.seq:
            if len(tmp) > count and len(elem) > count and elem[:count].lower() == tmp[:count].lower():
                checked = checked + 1
            elif len(tmp) > 0:
                checked = 0
            tmp = elem
        return checked if checked == len(self.seq) else self.len
        
    
    def find_occurence(self, dict):
        self.len = len(self.key)
        tmp = getcity(dict)
        self.seq = list(set([i for i in tmp if i.lower().startswith(self.key.lower())]))
        if len(self.seq) > 1:
            self.mp = self.getnextattribute()
            self.print_mp(tmp)
            return self.mp
        else:
            self.find_adress_with_city(dict)
            return self.seq
    
    def find_adress_with_city(self, dict):
        for elem in dict:
            if (elem.getcity().lower().find(self.seq[0].lower()) != -1):
                self.adress.append(elem.adress)
        if len(self.adress) == 1:
            print_result(self.seq[0], self.adress, dict)

    def setkey(self, key):
        self.key = key

    def __repr__(self) -> str:
        return self.key

    def print_mp(self, tmp):
        count = 0
        self.mp = sort_choice(self.mp, tmp)

        for elem in self.mp:
            count = count + 1
            print('{' + elem[:self.len].upper() + elem[self.len:].lower() + '}', end="")
            print('\n' if len(self.mp) == count else ' ', end="")

def print_result(city, adress, dict):
    for elem in dict:
        if elem.getcity().lower().find(city.lower()) != -1:
            print("=> " + elem.getcity() + ',' + adress[0])
            exit(0)

def getcity(dict):
    res = []
    for elem in dict:
        res.extend(elem.getcity().split())
    return res

def find_city_nbr(dict, city):
    counter = 0
    for elem in dict:
        if (elem[:len(city)].lower()  == city.lower()):
            counter = counter + 1
    return counter

def check_upper_order(tmp, mp):
        tmp.sort(key=lambda x: ord(x.key[len(x.key) - 1]))
        return tmp

def sort_choice(mp, dict):
    tmp = list()
    new_tmp = list()
    mp.sort(key=lambda x: ord(x[len(x) - 1]), reverse=True)
    for elem in mp:
        new_tmp.append(choice(find_city_nbr(dict, elem), elem))
    tmp.clear
    new_tmp = check_upper_order(new_tmp, mp)
    new_tmp.sort(key=lambda x: int(x.value), reverse=True)
    for elem in new_tmp:
        tmp.append(elem.key)
    return tmp