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

# try each beginning coin
# then for each beginning coin, try each second coin
# keep trying until no money needed
# if you cant use a particular coin because its more than the amount left, set to infinity so that its max and cant be used

'''
# coins it takes to reach target
using 1 as first coin: 1 + opt(i - 1)
using 4 as first coin: 1 + opt(i - 4)
using 5 as first coin: 1 + opt(i - 5)
where opt(i - n) returns the optimal # of coins -> minimum # of coins -> do 3 opts each with diff coins to see
opt(m) = min(opt(m - 1), opt(m - 4), opt(m - 5)) + 1

need to know how much money there is left
need to track which coins are being used
'''

coinslist = [1, 4, 5]


def goodnumcoinsrec(target, coins):
    if target == 0:
        return 0
    if target < 0:
        return float('inf')
    minnumcoins = float('inf')
    for coin in coins:
        minnumcoins = min(minnumcoins, goodnumcoinsrec(target-coin, coins) + 1)
    return minnumcoins

def fullnumcoinsrec(target, coins, coinsused):
    if target == 0:
        return 0, []
    if target < 0:
        return float('inf'), []
    minnumcoins = float('inf')
    for coin in coins:
        altoption, coinsused = fullnumcoinsrec(target-coin, coins, coinsused) + 1
        if altoption < minnumcoins:
            minnumcoins = altoption
            coinused = coin
    return minnumcoins, coinsused + [coinused]

# def numcoinsrec(target, coins):
#     if target - coins < 0:
#         return float(inf)
#     minnumcoins = 0
#     for coin in coins:
#         minnumcoins = 1 + min(numcoinsrec(target - 1), numcoinsrec(target - 4), numcoinsrec(target - 5))
#     return minnumcoins

# def numcoinsrec(target, coins):
#     if target - coins < 0:
#         return float(inf)
#     minnumcoins = 0
#     for coin in coins:
#         minnumcoins = 1 + min(numcoinsrec(target - 1), numcoinsrec(target - 4), numcoinsrec(target - 5))
#     return minnumcoins

# def numcoinsrec(target, coins, opt):
#     if target - coins < 0:
#         return float(inf)
#     minnumcoins = 0
#     for coin in coins:
#         minnumcoins = 1 + min(numcoinsrec(target - 1), numcoinsrec(target - 4), numcoinsrec(target - 5))
#         opt.append(coin)
#     return minnumcoins

## brainstorm:
# def coins(target, coinslist):
#     minnumcoins = float(inf)
#     for coin in coinslist:
#         minnumcoins = min(opt(n - coin, coin) + 1, minnumcoins)

# def opt(moneyremaining, coin, coinlist):
#     if moneyremaining - coin < 0:
#         return float(inf)
#     return 1 + opt(moneyremaining, coins)

# def coins(target, coinslist):
#     for coin in coinslist:
#         opt(n, coin)

# def opt(n, coin):
#     numcoin = n // coin
#     untiltarget = n % coin
#     return untiltarget, numcoin

# def opt(n, coin):
#     if coin - n < 0:
#         return float(inf)
#     m = n
#     while (coin - m > 0):
#         if 
#     return

# Part (b)
# Write code to compute OPT(0), then OPT(1), then OPT(2), ..., then OPT(n). You should write a function
# that takes in the denominations list and the target amount, and returns the OPT list.
# Part (c)
# Write code that returns a list of the coins you need to make up a target amount, when the least possible
# number of coins is used. (For example, the function would return [4, 4], if the denominations are
# [1c, 4c, 5c] and the target is 8).
# Follow the example from houses.py. The first coin used, denom, should be such that 1 + OPT(n-denom)
# is as small as possible. To determine the next coin, denom2, make 1 + 1 + OPT(n-denom-denom2) as
# small as possible.
# (Note: it is possible to keep track of the coins used when computing OPT, but here we are asking for
# you to do something analogous to houses.py).



# Question 3. 2024 Exam Question
# Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if
# s can be segmented into a space-separated sequence of one or more dictionary words.
# Write a function canBeSegmented(s, wordDict) that returns True if s can be segmented and False
# otherwise.
# If you are given:
# s = ”applepenpple”,
# wordDict = [”apple”, ”pen”],
# The output should be True because "applepenpple" can be segmented as "apple pen apple".
# Engineering Science, University of Toronto Page 1 of 2
# ESC 190 H1F Labs #8 Winter 2025
# If you are given:
# s = ”catsandog”,
# wordDict = [”cats”, ”dog”, ”sand”, ”and”, ”cat”],
# The output should be False because "catsandog" cannot be segmented into a space-separated
# sequence of one or more dictionary words.
# Hint: the string s can be segmented if there is a word word in wordDict such that word is a prefix of
# s and s[len(word):] can be segmented.

'''
first word matters - check against every word in dict
then keep going
'''

def canBeSegmented(s, wordDict):
    if s == '':
        return True
    for word in wordDict:
        for i in range (len(word)):
            if s[i] == word[i] and canBeSegmented(s[len(word):]):
                return True
    return False

def solcanbesegmented(s, wordDict):
    if s == '':
        return True
    for word in wordDict:
        if s.startswithword(word):
            if canBeSegmented(s[len(word):], wordDict):
                return True
    return False

## string slicing
'''
[start:] means everything after start excluding start except for the last char in start
[2:] means everything including and after index 2
[2:5] means get the characters from position 2 (included) to position 5 (not included)
[:5] means get the characters from the start to position 5 (not included):
'''