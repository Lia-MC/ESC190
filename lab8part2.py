# 2a: 
# OPT(n) = 1 + min(OPT(n-d1), OPT(n-d2), OPT(n-d3), OPT(n-d4)...)

# 2b:

def minCoins(t, denominations, OPT = {}): # calculate minimum number of coins needed for each value of money given
    if OPT == {}:
        for i in denominations:
            OPT[i] = 1
    if t == 0:
        OPT[t] = 0
        return dict(sorted(OPT.items())) 
    if t < 0: # considering money should be positive
        OPT[t] = float('inf')
        return dict(sorted(OPT.items())) 
    if t in OPT:
        return dict(sorted(OPT.items())) 

    cur_min = float('inf')
    for i in denominations:
        if (t - i) >= 0:
            OPT = minCoins(t - i, denominations, OPT) 
            cur_min = min(cur_min, OPT[t - i])

    OPT[t] = 1 + cur_min
    return dict(sorted(OPT.items())) 

# 2c:

def findMinCoins(t, denominations, OPT, denom = []): # find which coins to actually use for minimum number of coins
    cur_denom = 0
    cur_min = float('inf')
    for i in denominations:
        if (t - i == 0):
            cur_denom = i
            denom.append(cur_denom)
            return denom
        if (t - i > 0):
            if OPT[t - i] < cur_min:
                cur_min = OPT[t - i]
                cur_denom = i
    denom.append(cur_denom)
    findMinCoins(t - cur_denom, denominations, OPT, denom)
    return denom

OPT = minCoins(40, [1, 4, 5, 10])
print(OPT)
print(findMinCoins(27, [1, 4, 5, 10], OPT))

# 3:
# keep searching until theres either no more words in the string or theres a word thats not in the word bank

def canBeSegmented(s, wordDict):
    i = 1
    while s[:i] not in wordDict:    
        if i == len(s):
            return False
        i += 1
    if i == len(s):
        return True
    return canBeSegmented(s[i:], wordDict) 
    
print(canBeSegmented('applepenapple', ['apple', 'pen'])) # should be true because 
print(canBeSegmented('catsandog',  ["cats", "dog", "sand", "and", "cat"])) # should be false because the and/sand 
# will overlap with dog so it cant be directly separated into words in the word dict if word dict is restricted
# to those five words only