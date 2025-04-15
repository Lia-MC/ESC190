# // Question 8. [10 marks]
# // Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if
# // s can be segmented into a space-separated sequence of one or more dictionary words.
# // Write a function canBeSegmented(s, wordDict) that returns true if s can be segmented and false
# // otherwise.
# // Example
# // 1. If you are given:
# // s = ”applepenapple”,
# // wordDict = [”apple”, ”pen”],
# // The output should be true because ”applepenapple” can be segmented as ”apple pen apple”.
# // 2. If you are given:
# // s = ”catsandog”,
# // wordDict = [”cats”, ”dog”, ”sand”, ”and”, ”cat”],
# // The output should be false because ”catsandog” cannot be segmented into a space-separated sequence of one or more dictionary words.
# // Notes
# // • The same word in the dictionary may be reused multiple times in the segmentation.
# // • You may assume the dictionary does not contain duplicate words.
# // You must use dynamic programming

# when it says you must use dynamic programming what does that mean? do i need to identify top down or bottom up?
# or do i just need to solve the problem? do i need to use recursion? (no) do i need to play with memory allocation? (no)

def canBeSegmented(s, wordDict):
    ## non empty string s
    ## list of non empty words worddict
    # base case: nothing in the string then true
    # other cases: cannot be 
    # start at the first smallest word and look up if you can segment in that way
    # dfs or bfs OHHHH does dynamic programming mean use dfs or bfs?

    # for letter in s:
    #     curword = ""
    #     while (curword not in wordDict):
    #         curword.append(letter)
        
    #     find smallest word in worddict starting with this letter and segment it like that for all
    #     find next smallest word in worddict starting with this letter

    # there are many ways to segment
    # i can segment cat sand og  or cats and og  or but these cant actually be segmented
    # the first word can have multiple ways to be segmented
    # then the second word is based on first word, and can have multiple ways to be segmented

    wordfound = False

    while wordfound == False:
        curword += letter

    # want to find all possibilities of each word
    # start at cat and cats
    # if cat then sand if cats then and
    # if sand then og isnt in dict

    arr = []
    thissegment = True
    lenarr = 0

    for letter in s:
        arr.append(letter)
        lenarr += 1

    for word in wordDict:
        lenword = len(word)
        counter = 0
        for i in range(0, lenword):
            counter += 1
            if arr[i] != word[i]:
                thissegment = False
        if thissegment == True and counter == lenarr:
            return True
        elif thissegment == True:
            return canBeSegmented(arr[counter:], wordDict)
    return False

def properCanBeSegmented(s, wordDict):
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