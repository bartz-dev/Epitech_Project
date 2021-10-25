#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## B-MAT-400-LYN-4-1-203hotline-arthur1.perrot
## File description:
## unit_test.py
##

import unittest
from utils import binomial_coef

class TestOutput(unittest.TestCase):

    def test_first(self):
        self.assertEqual(binomial_coef(100, 18), 30664510802988208300)

    def test_second(self):
        self.assertEqual(binomial_coef(100, 1), 100)

    def test_third(self):
        self.assertEqual(binomial_coef(180, 10), 7628275984984380)

if __name__ == "__main__":
    unittest.main()