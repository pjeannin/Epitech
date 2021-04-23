#!/usr/bin/python3

import sys
import math

def formatNumber(number, n):
    retVal = str(round(number, n))
    count = 0
    start = False
    for c in retVal:
        if start == False:
            if c == '.':
                start = True
        else:
            count += 1
    if count != 0:
        for i in range(0, n - count):
            retVal += '0'
    else:
        retVal += ".00"
    return retVal

def computeAverage(values, period):
    average = 0
    for i in range(1, period + 1):
        average += values[-i]
    return average / period

def computePositivAverage(values, period):
    average = 0
    count = 0
    for i in range (1, period + 1):
        tmp = values[-i] - values[-i - 1]
        if tmp > 0:
            count += 1
            average += tmp
    if count == 0:
        return 0
    return average / period

def computeSigma(values, average, period):
    res = 0
    for i in range(1, period + 1):
        res += (average - values[-i]) ** 2
    res /= period
    return math.sqrt(res)

def computeRelativEvolution(values, period):
    if values[-1 - period] == 0:
        return (values[-1] + 1) / (values[-1 - period] + 1) * 100 - 100
    return (values[-1] / values[-1 - period]) * 100 - 100

if len(sys.argv) != 2:
    print("Incorrect usage, please use ./groundhog -h to know how to use it.")
    exit(84)
if sys.argv[1] == "-h":
    print("SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\t\tthe number of days defining a period")
    exit(0)
try:
    period = int(sys.argv[1])
except:
    print("'period' must be an integer greater than 1.")
    exit(84)
if period <= 1:
    print("'period' must be an integer greater than 1.")
    exit(84)
values = []
ecarts = []
try:
    line = input()
except:
    print("Oops, can't read.")
    exit(84)
relativEvolution = -999999999
prevRelativEvolution = -999999999
switch = False
switchs = 0
while line != "STOP":
    value = 0.0
    try:
        value = float(line)
    except:
        print("Bad input.")
        exit(84)
    values.append(value)
    print("g=", end='')
    if len(values) < period + 1:
        print("nan", end='    ')
    else:
        positivAverage = computePositivAverage(values, period)
        print(formatNumber(positivAverage, 2), end='    ')
    if len(values) < period + 1:
        print("r=nan%", end='    ')
    else:
        prevRelativEvolution = relativEvolution
        relativEvolution = int(round(computeRelativEvolution(values, period), 0))
        if prevRelativEvolution != -999999999 and prevRelativEvolution * relativEvolution < 0:
            switch = True
        print("r=" + str(relativEvolution) + "%", end='    ')
    if len(values) < period:
        print("s=nan", end='    ')
    else:
        average = computeAverage(values, period)
        sigma = computeSigma(values, average, period)
        low = average - 2 * sigma
        up = average + 2 * sigma
        if value < average:
            ecarts.append(low - value)
        else:
            ecarts.append(value - up)
        print("s=" + formatNumber(sigma, 2), end='')
    if switch == True:
        switch = False
        switchs += 1
        print("    a switch occurs")
    else:
        print("")
    try:
        line = input()
    except:
        print("Oops, can't read.")
        exit(84)
if len(values) < period:
    print("Not enough values")
    exit(84)
print("Global tendency switched", switchs, "times")
tmp = sorted(ecarts)
final = tmp[-5:]
final = list(map(lambda x : values[ecarts.index(x) + period - 1], final))
print("5 weirdest values are {}".format(final[::-1]))
exit(0)