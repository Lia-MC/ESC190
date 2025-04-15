# Question 2.
# For this question, you will want to work in Python.
# Consider the problem we introduced in lecture: we want to make up an amount of money using
# coins from a given set of denominations, using the least possible number of coins. For example, if our
# denominations are [1c, 4c, 5c], the most efficient way to make up 8c is with two coins, 4c + 4c.
# Part (a)
# Suppose you have computed OPT(0), OPT(1), OPT(2), ..., OPT(n-1), the numbers of coins that are
# needed to make up 0c, 1c, 2c, ..., (n-1)c.
# Write down an expression for OPT(n), in terms of the denominations and OPT(0), ...., OPT(n).
# Hint: if you want to use the 5c coin, the total number of coins you’ll need is OPT(n-5)+1

# Part (b)
# Write code to compute OPT(0), then OPT(1), then OPT(2), ..., then OPT(n). You should write a function
# that takes in the denominations list and the target amount, and returns the OPT list.

def opt(denoms, target):
    # Initialize with "infinity" — we assume we haven't found a way yet
    numcoins = [float('inf')] * (target + 1)
    numcoins[0] = 0  # base case

    for i in range(1, target + 1):
    # iterate through each value, bottom up, from 1 to target cost (0 has been computed)
        for coin in denoms:
            if i - coin >= 0:
                numcoins[i] = min(numcoins[i], numcoins[i - coin] + 1) 
                # compare the cur val stored in numcoins agains each coin denom

    return numcoins

def badopt(denoms, target):
    numcoins = [0] * (target + 1)
    numcoins[0] = 0
    # mincost = [0] * (target + 1) 
    # mincost[0] = 0
    for denom in denoms:
        numcoins[denom] = 1
        # mincost[denom] = denom
    for i in range(len(denoms), target + 1):
        if numcoins[i] == 0:
            numcoins[i] = 1 + opt(denoms, target - denoms[i])
            # mincost[i] =  
    return numcoins

# Part (c)
# Write code that returns a list of the coins you need to make up a target amount, when the least possible
# number of coins is used. (For example, the function would return [4, 4], if the denominations are
# [1c, 4c, 5c] and the target is 8).
# Follow the example from houses.py. The first coin used, denom, should be such that 1 + OPT(n-denom)
# is as small as possible. To determine the next coin, denom2, make 1 + 1 + OPT(n-denom-denom2) as
# small as possible.
# (Note: it is possible to keep track of the coins used when computing OPT, but here we are asking for
# you to do something analogous to houses.py).


def badbestcoinpath(denom, target):
    best = [0] * (target + 1)
    bestpath = []
    mincoins = ['inf'] * (target + 1)
    
    for i in range(1, target + 1):
        for coin in denom:
            if (mincoins[i] > opt(denom, i)):
                mincoins[i] = opt(denom, i)
                best[i] = coin
    
    i= target

    while(i >= 0):
        bestpath[i] = best[i]
        i = i - best[i]

    return bestpath

def goodbestcoinpath(denoms, target):
    # Step 1: Compute the OPT (min number of coins) array
    opt = [float('inf')] * (target + 1)
    opt[0] = 0
    firstcoin = [0] * (target + 1)  # Store the first coin used for each value

    for i in range(1, target + 1):
        for coin in denoms:
            if i - coin >= 0 and opt[i - coin] + 1 < opt[i]:
                opt[i] = opt[i - coin] + 1
                firstcoin[i] = coin

    # Step 2: Reconstruct path using firstcoin[]
    path = []
    while target > 0:
        coin = firstcoin[target]
        path.append(coin)
        target -= coin

    return path
