##
## EPITECH PROJECT, 2020
## B-CNA-410-LYN-4-1-trade-clement.fleur
## File description:
## candle.py
##

class candles:
    def __init__(self, data):
        self.pair = data[0]
        self.date = float(data[1])
        self.high = float(data[2])
        self.low = float(data[3])
        self.open = float(data[4])
        self.close = float(data[5])
        self.volume = float(data[6])