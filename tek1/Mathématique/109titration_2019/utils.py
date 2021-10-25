##
## EPITECH PROJECT, 2019
## 109titration_2019
## File description:
## utils.py
##

def preparelist(list2):
    list = []
    for i in range(0, len(list2)):
        if len(list2[i]) > 3:
            list.append(resultfloatconv(list2[i]))
        else:
            list.append(int(list2[i][2]))
    return list

def resultfloatconv(list3):
    i = 0

    while list3[i] != ';':
        i = i + 1
    i += 1
    nbr = float(list3[i:])
    return nbr

def errorhandling(list):
    for i in range(0, len(list)):
        if len(list[i]) < 3:
            return 84
        for p in range(0, len(list[i])):
            if (my_isint(list[i][p]) or list[i][p] == ';' or
            list[i][p] == '.') == False:
                return 84
            if (len(list[i]) > 8 or ccount(';', list[i]) > 1 or
            ccount(';', list[i]) < 1):
                return 84

def my_isint(nbr):
    try:
        int(nbr)
        return True
    except ValueError:
        return False

def ccount(c, list):
    count = 0
    for i in range(0, len(list)):
        if list[i] == c:
            count = count + 1
    return count