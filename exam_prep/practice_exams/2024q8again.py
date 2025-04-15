# Question 8. [10 marks]
# Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if
# s can be segmented into a space-separated sequence of one or more dictionary words.
# Write a function canBeSegmented(s, wordDict) that returns true if s can be segmented and false
# otherwise.
# Example
# 1. If you are given:
# s = ”applepenapple”,
# wordDict = [”apple”, ”pen”],
# The output should be true because ”applepenapple” can be segmented as ”apple pen apple”.
# 2. If you are given:
# s = ”catsandog”,
# wordDict = [”cats”, ”dog”, ”sand”, ”and”, ”cat”],
# The output should be false because ”catsandog” cannot be segmented into a space-separated sequence of one or more dictionary words.
# Notes
# • The same word in the dictionary may be reused multiple times in the segmentation.
# • You may assume the dictionary does not contain duplicate words.
# You must use dynamic programming.

# initialize base cases in memoization memo
# empty list, add base cases, build off

def bottomup_canBeSegmented(s, wordDict):
    n = len(s) # stores the length of this string
    dp = [False] * (n + 1) # have an extra space more than the length??? no, first one is if its empty i think
    dp[0] = True  # empty string is always segmentable

    for i in range(1, n + 1): # from first letter to last where n is last so n + 1 is exclusive
        for j in range(i):
            if dp[j] and s[j:i] in wordDict: # if dynamicprogrammingarray is equal to a substring
                dp[i] = True
                break  # no need to check more splits if one works

    return dp[n]

def topdown_canBeSegmented(s, wordDict):
    memo = {} # make the memo cache where i store stuff

    def helper(str):
        if str in memo: # Check if the remaining part of the string is alr a word, if so we dont have to recalculate it
            return memo[str]
        if str == "": # if theres nothing left and weve gotten up to that point, gj, its all segmentable
            return True
        for word in wordDict: # if remaining string is a jumble of words still, then check with every word in dict
            if str.startswith(word): # if the remaining string starts with the word then 
                if helper(str[len(word):]): # check the remaining part of the remaining string and if it's segmentable
                    memo[str] = True # we know that the remaining part is all segmentable
                    return True # we know the whole thing is segmentable
        memo[str] = False # if the remaining part of a string is not segmentable then the whole thing is not segmentable
        return False # if none of these conditions are met then oh well

    return helper(s)

def finalCanBeSegmented(s, wordDict):
    i = 1 # because :i is exclusive so its inclusive of 0 so its just the first char for the first loop
    while s[:i] not in wordDict:
        if (len(s) == i): ## if ive gotten to the end of the string and havent yet found anything
            return False
        i += 1
    if len(s) == i: ## if i found smth and have gotten to the end of the string
        return True
    return finalCanBeSegmented(s[i:], wordDict) 
    ## condition will be reached when word in dictionary is found, but we havent reached the end of string so theres more to check

def workingOnCanBeSegmentedWordByWord(s, wordDict):
    i = 1 # because :i is exclusive so its inclusive of 0 so its just the first char for the first loop
    while s[:i] not in wordDict:
        i += 1
    if canBeSegmentedWordByWord(s[i:], wordDict):
        return True
    return False

def badCanBeSegmented(s, wordDict):
    ds = [False]
    for word in wordDict:
        if s[:len(word)] is word:
            return canBeSegmented(s[len(word):], wordDict)
    return False

def attemptedCanBeSegmented(s, wordDict):
    # ds = [False] * (len(s) + 1) ## this isnt doing anything...
    for word in wordDict:
        if s[:len(word)] is word:
            return canBeSegmented(s[len(word):], wordDict)
    return False