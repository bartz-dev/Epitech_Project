##
## EPITECH PROJECT, 2020
## B-CNA-410-LYN-4-1-trade-clement.fleur
## File description:
## strategy.py
##

from heikinAshi import heikinashi
from time import *
import sys

started_balance = {"USDT_BTC" : 0.0, "USDT_ETH" : 0.0, "BTC_ETH" : 0.0}

class strategy:
    def __init__(self):
        self.pair = []
        self.current_pair = []

    def find_pair(self, param):
        #on cherche les 3 devises différentes
        for res in param.data:
            if self.pair.count(res.pair) == 0:
                self.pair.append(res.pair)

    def heikin_ashi(self, pair, value, param):
        isBuyable = False
        self.current_pair = []
        #on recupère les info de la paire recherché
        for i in range(len(value)):
            if (value[i].pair == pair):
                self.current_pair.append(heikinashi(value, i))
        isBuyable = verysimpleMA(self.current_pair, 7)
        if (isBuyable == True and pair != "BTC_ETH" and param.stacks["USDT"] >= 100):
            sys.stdout.write(buyOrder(pair, param.stacks["USDT"], self.current_pair[len(self.current_pair) - 1]))
            return 1
        else:
            return 0


    def start(self, param):
        self.find_pair(param)
        for pair in self.pair:
            if (self.heikin_ashi(pair, param.data, param) == 1 and param.stacks[pair[pair.find('_') + 1: len(pair)]] == 0.0):
                return 1
            elif (started_balance[pair] != 0.0 and calculate_increase(started_balance[pair], self.current_pair[len(self.current_pair) - 1].close) >= 10) or calculate_increase(self.current_pair[len(self.current_pair) - 1].close, started_balance[pair]) >= 3:
                sys.stdout.write(sellOrder(pair, param.stacks[pair[pair.find('_') + 1: len(pair)]]))
                return 1


        sys.stdout.write("pass\n")

def verysimpleMA(values, period):
    iterate = len(values) - len(values)%period
    iterate /= period
    ma = list()
    res = 0.0
    count = 0

    for i in range(len(values)%period, len(values)):
        if count%period == 0:
            ma.append(res/period)
            res = 0.0
        else:
            res += values[i].close
        count += 1
    if (calculate_increase(ma[len(ma) - 1], ma[len(ma) - 2]) > 2):
       return True
    return False

def calculate_increase(first, second):
    return (second-first)/first*second

def buyOrder(pair, money, value):
    global started_balance
    r = float(money*0.6)/float(value.close)

    if (int(r*0.98) == 0):
        return "pass\n"
    started_balance[pair] = float(value.close)
    return ("buy " + pair + ' ' + "%d" % (r*0.98) + '\n')

def sellOrder(pair, money):
    global started_balance
    if (int((money *0.99)) == 0):
        return "pass\n"
    started_balance[pair] = 0.0
    return ("sell " + pair + ' ' + "%d" % (money *0.99) + '\n')