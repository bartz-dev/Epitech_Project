##
## EPITECH PROJECT, 2020
## B-MAT-400-LYN-4-1-202unsold-arthur1.perrot [WSL: Debian]
## File description:
## expected_var.py
##

from z_law import PopZ

def get_expected(law):
    result = law[0] * 10 + law[1] * 20 + law[2] * 30 + law[3] * 40 + law[4] * 50
    return round(result, 1)

def get_Zexpected(law):
    result = law[0] * 20 + law[1] * 30 + law[2] * 40 + law[3] * 50 + law[4] * 60 + law[5] * 70 + law[6] * 80 + law[7] * 90 + law[8] * 100
    return round(result, 1)

def get_variance(law):
    expected = get_expected(law)
    result = (((10 - expected) ** 2) * law[0] ) + \
                                        (((20 - expected) ** 2) * law[1] ) + \
                                        (((30 - expected) ** 2) * law[2] ) + \
                                        (((40 - expected) ** 2) * law[3] ) + \
                                        (((50 - expected) ** 2) * law[4] )
    return round(result, 1)

def get_Zvariance(law):
    expected = get_Zexpected(law)
    result =                            (((20 - expected) ** 2) * law[0] ) + \
                                        (((30 - expected) ** 2) * law[1] ) + \
                                        (((40 - expected) ** 2) * law[2] ) + \
                                        (((50 - expected) ** 2) * law[3] ) + \
                                        (((60 - expected) ** 2) * law[4] ) + \
                                        (((70 - expected) ** 2) * law[5] ) + \
                                        (((80 - expected) ** 2) * law[6] ) + \
                                        (((90 - expected) ** 2) * law[7] ) + \
                                        (((100 - expected) ** 2) * law[8] )
    return round(result, 1)

def expected_variance_display(ResValues, xLaw, yLaw):
    zLaw = PopZ()
    print("expected value of X:\t", end="")
    print(get_expected(xLaw))
    print("variance of X:\t\t", end="")
    print(get_variance(xLaw))
    print("expected value of Y:\t", end="")
    print(get_expected(yLaw))
    print("variance of Y:\t\t", end="")
    print(get_variance(yLaw))
    print("expected value of Z:\t", end="")
    print(get_Zexpected(zLaw))
    print("variance of Z:\t\t", end="")
    print(get_Zvariance(zLaw))