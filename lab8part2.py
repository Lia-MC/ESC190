# Question 2
# a: OPT(n) = 1 + min(OPT(n-d1), OPT(n-d2), OPT(n-d3), OPT(n-d4)...)

# b:

def minCoins(t, demoninations, OPT = {}):
    if OPT == {}:
        for i in demoninations:
            OPT[i] = 1
    if t == 0:
        OPT[t] = 0
        return dict(sorted(OPT.items())) 
    if t < 0:
        OPT[t] = float('inf')
        return dict(sorted(OPT.items())) 
    if t in OPT:
        return dict(sorted(OPT.items())) 

    cur_min = float('inf')
    for i in demoninations:
        if (t - i) >= 0:
            OPT = minCoins(t - i, demoninations, OPT) 
            cur_min = min(cur_min, OPT[t - i])

    OPT[t] = 1 + cur_min
    return dict(sorted(OPT.items())) 

# c:

def findMinCoins(t, denominations, OPT, denom = []):
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

# Question 3

def canBeSegmented(s, wordDict):
    i = 1
    while s[:i] not in wordDict:    
        if i == len(s):
            return False
        i += 1
    if i == len(s):
        return True
    return canBeSegmented(s[i:], wordDict) 
    
print(canBeSegmented('applepenapple', ['apple', 'pen']))
print(canBeSegmented('catsandog',  ["cats", "dog", "sand", "and", "cat"]))