##
## EPITECH PROJECT, 2020
## B-CNA-410-LYN-4-1-trade-clement.fleur
## File description:
## bot.py
##

import sys
from candle import candles
from strategy import strategy
from datetime import datetime


class Bot:
    def __init__(self):
            self.timebank = None
            self.time_per_move = None
            self.player_names = None
            self.your_bot = None
            self.candle_interval = None
            self.candle_format = None
            self.candles_total = None
            self.candles_given = None
            self.initial_stack = None
            self.line = None
            self.data = []
            self.stacks = {}

    def settings(self):
        setattr(self, self.line[1], self.line[2])


    def run(self):
        self.line = input()

        while (len(self.line) > 0):
            try:
                self.line = self.line.split(' ', 4)
                res = eval('self.' + self.line[0] + '()')

                if (res and len(res) > 0):
                    sys.stdout.write(res)
            except:
                sys.stderr.write("error can't parse !\n")
            try:
                self.line = input()
            except EOFError:
                print("error")
                exit(0)

    def update(self):
        #lancer quand update envoyé en première argument
        if (self.line[1] != "game"):
            return 84;

        if (self.line[2] == "next_candles"):
            self.update_candles()
        elif (self.line[2] == "stacks"):
            self.update_stacks()

    def update_stacks(self):
        #update du solde du compte
        tmp = self.line[3].split(',')
        for elem in tmp:
            res = elem.split(':')
            self.stacks[res[0]] = float(res[1])

    def update_candles(self):
        #update de la data
        tmp = self.line[3].split(';', 3)
        for elem in tmp:
            elem = elem.split(',', 6)
            self.data.append(candles(elem))

    def action(self):
        # quand action est envoyé en premier argument d'entrée
        if (self.line[1] == "order"):
                self.timebank = int(self.line[2])
                strat = strategy()
                if (strat.start(self)) == 0:
                    print("pass\n")

    def convert_candle_with_time (self, number):
        time = datetime.fromtimestamp(self.data[1].date)
        print (time)
