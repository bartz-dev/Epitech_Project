##
## EPITECH PROJECT, 2021
## B-SYN-400-LYN-4-1-autoCompletion-clement.fleur [WSL: Ubuntu]
## File description:
## algorithm.py
##

from utils import get_digit

streettype = ["allée", "avenue", "boulevard", "chemin", "impasse", "place", "quai", "rue", "square"]

class adress:
    def __init__(self, city, adress):
        self.city = city
        self.adress = adress
        self.number = get_digit(adress)

    def getStreetType(self):
        for elem in streettype:
            if self.adress.find(elem) != -1:
                return elem

    def getcity(self):
        return self.city
    
    def __str__(self) -> str:
        return self.city + ',' + self.adress

    def __repr__(self) -> str:
        return self.city + ',' + self.adress
    
    def __eq__(self, other) -> bool:
        return self.city == other.city and self.adress == other.adress

    def __hash__(self) -> int:
        return hash(('city', self.city, 'adress', self.adress))