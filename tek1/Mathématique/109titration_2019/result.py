##
## EPITECH PROJECT, 2019
## 109titration_2019
## File description:
## result.py
##

def ispositive(num):
    if num > 0:
        return True
    elif num == 0:
        return 0
    else:
        return False

def writingresult(result, min, maxi):
    value = 1.0
    secvalue = 1.0
    posnbr = 0
    for i in range(0, len(result)):
        if ispositive(result[i]) == False:
            posnbr = float(result[i]*(-1))
        else:
            posnbr = float(result[i])
        if (value - posnbr) > (value - secvalue):
            secvalue = float(posnbr)
            p = i
    value = min + (p*0.1)
    print("\nEquivalence point at", value, "ml")