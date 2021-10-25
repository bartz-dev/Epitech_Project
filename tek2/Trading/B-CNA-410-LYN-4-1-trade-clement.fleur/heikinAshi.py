##
## EPITECH PROJECT, 2020
## B-CNA-410-LYN-4-1-trade-clement.fleur
## File description:
## heikinAshi.py
##

class heikinashi:
    def __init__(self, candles, index):
        self.close = (candles[index].open + candles[index].high + candles[index].low + candles[index].close)/4
        self.open = (candles[self.find_last_occurence(candles, index)].open + candles[self.find_last_occurence(candles, index)].close)/2
        self.high = candles[index].high
        self.low = candles[index].low

    def find_last_occurence(self, candles, index):
        i = index
        while (i != 0):
            i -= 1
            if (candles[i].pair == candles[index].pair):
                return i
        return index

    def is_negative(self):
        if (self.close < self.open):
            return True
        return False

    def is_positive(self):
        if (self.close > self.open):
            return True
        return False


""" TODO
def ohlc(ha_candles):
"""
