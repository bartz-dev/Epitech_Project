##
## EPITECH PROJECT, 2019
## 108trigo_2019
## File description:
## utils.py
##

def printhelp():
    print("USAGE\n"
          "\t./108trigo fun a0 a1 a2....\n"
          "\n"
          "DESCRIPTION\n"
          "\tfun\tfunction to be applied,"
          ' among at least "EXP", "COS", "SIN", "COSH" and "SINH"\n'
          '\tai\tcoeficients of the matrix')
    exit(0)

def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print("%.2f%c" % (matrix[i][j], '\t' if (j != len(matrix[i]) - 1) else '\n'), end="")
