#!/usr/bin/python3

import sys
import math
import matplotlib.pyplot as plt

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
averages = []
averagesIndexs = []
sigmasPlus = []
sigmasMoins = []
sigmasIndexs = []
index = 0
line = input()
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
        print("nan", end='      ')
    else:
        positivAverage = computePositivAverage(values, period)
        print(formatNumber(positivAverage, 2), end='      ')
    if len(values) < period + 1:
        print("r=nan%", end='      ')
    else:
        prevRelativEvolution = relativEvolution
        relativEvolution = int(round(computeRelativEvolution(values, period), 0))
        if prevRelativEvolution != -999999999 and prevRelativEvolution * relativEvolution < 0:
            switch = True
        print("r=" + str(relativEvolution) + "%", end='      ')
    if len(values) < period:
        print("s=nan", end='      ')
    else:
        print("s=" + formatNumber(computeSigma(values, computeAverage(values, period), period), 2), end='      ')
        sigmasPlus.append(2 * computeSigma(values, computeAverage(values, period), period) + computeAverage(values, period))
        sigmasMoins.append(computeAverage(values, period) - 2 * computeSigma(values, computeAverage(values, period), period))
        sigmasIndexs.append(index)
        averages.append(computeAverage(values, period))
        averagesIndexs.append(index)
    if switch == True:
        switch = False
        switchs += 1
        print("a switch occurs")
    else:
        print("")
    line = input()
    index += 1
print("Global tendency switched", switchs, "times")
plt.plot(values)
plt.plot(averagesIndexs,averages)
plt.plot(sigmasIndexs, sigmasPlus)
plt.plot(sigmasIndexs, sigmasMoins)
plt.show()
exit(0)