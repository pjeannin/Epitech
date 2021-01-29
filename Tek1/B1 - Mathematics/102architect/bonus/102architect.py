#!/usr/bin/python3

import sys
import math
from pylab import *

def add_translation(x, y):
    ligne = []
    tab = []
    ligne.append(1)
    ligne.append(0)
    ligne.append(int(x))
    tab.append(ligne)
    ligne = []
    ligne.append(0)
    ligne.append(1)
    ligne.append(int(y))
    tab.append(ligne)
    ligne = []
    ligne.append(0)
    ligne.append(0)
    ligne.append(1)
    tab.append(ligne)
    matrix_tab.append(tab)
    return

def add_scaling(x, y):
    ligne = []
    tab = []
    ligne.append(int(x))
    ligne.append(0)
    ligne.append(0)
    tab.append(ligne)
    ligne = []
    ligne.append(0)
    ligne.append(int(y))
    ligne.append(0)
    tab.append(ligne)
    ligne = []
    ligne.append(0)
    ligne.append(0)
    ligne.append(1)
    tab.append(ligne)
    matrix_tab.append(tab)
    return


def add_rotation(o):
    ligne = []
    tab = []
    o = int(o)
    o = (math.pi * o) / 180
    ligne.append(math.cos(o))
    ligne.append(- math.sin(o))
    ligne.append(0)
    tab.append(ligne)
    ligne = []
    ligne.append(math.sin(o))
    ligne.append(math.cos(o))
    ligne.append(0)
    tab.append(ligne)
    ligne = []
    ligne.append(0)
    ligne.append(0)
    ligne.append(1)
    tab.append(ligne)
    matrix_tab.append(tab)
    return


def add_symetry(o):
    ligne = []
    tab = []
    o = int(o)
    o = ((math.pi * o) / 180) * 2
    ligne.append(math.cos(o))
    ligne.append(math.sin(o))
    ligne.append(0)
    tab.append(ligne)
    ligne = []
    ligne.append(math.sin(o))
    ligne.append(-math.cos(o))
    ligne.append(0)
    tab.append(ligne)
    ligne = []
    ligne.append(0)
    ligne.append(0)
    ligne.append(1)
    tab.append(ligne)
    matrix_tab.append(tab)
    return

def arg_in_matrix(list):
    i = 3
    while i < len(list):
        if list[i] == "-t":
            add_translation(list[i + 1], list[i + 2])
            i += 3
        elif list[i] == "-z":
            add_scaling(list[i + 1], list[i + 2])
            i += 3
        elif list[i] == "-r":
            add_rotation(list[i + 1])
            i += 2
        elif list[i] == "-s":
            add_symetry(list[i + 1])
            i += 2
        else:
            exit(84)
    k = len(matrix_tab) - 1
    i = 0
    while i < k:
        matrix_tab[i], matrix_tab[k] = matrix_tab[k], matrix_tab[i]
        k -= 1
        i += 1
    return

def display_matrix(matrix):
    for i in range (3):
        for j in range (3):
            if j != 2:
                print(round(matrix[i][j], 2), end='')
                if round(matrix[i][j], 2) < 0:
                    print("   ", end='')
                else:
                    print("    ", end="")
            else:
                print(round(matrix[i][j], 2))
    return

def mul_matrix(mat1, mat2):
    res = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    for i in range (3):
        for j in range (3):
            for k in range (3):
                res[i][j] += mat1[i][k] * mat2[k][j]
    return res

def mul_matrix_tab(tab):
    res = tab[0]
    for i in range (1, len(tab)):
        res = mul_matrix(res, tab[i])
    return res



try:
    matrix_tab = []
    res_tab = []
    index_matrix = 0
    arg_in_matrix(sys.argv)
    res_tab = mul_matrix_tab(matrix_tab)
    display_matrix(res_tab)
    a = ((res_tab[0][0] * int(sys.argv[1])) + (res_tab[0][1] * int(sys.argv[2])) + res_tab[0][2])
    b = ((res_tab[1][0] * int(sys.argv[1])) + (res_tab[1][1] * int(sys.argv[2])) + res_tab[1][2])
    print("(", end="")
    print(sys.argv[1], end="")
    print(".00", end="")
    print(",", sys.argv[2], end="")
    print(".00", end="")
    print(")", "=>", "(", end="")
    print(round(a, 2), end="")
    print(",", round(b, 2), end="")
    print(")")
    plot(int(sys.argv[1]), int(sys.argv[2]), "ro", c="coral", label="start")
    plot(a, b, "ro", c="blue", label="end")
    axis("equal")
    legend()
    grid()
    show()
except:
    print("err")
    exit(84)

