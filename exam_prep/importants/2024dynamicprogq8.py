# =====================================
# TOP-DOWN DYNAMIC PROGRAMMING
# (Recursive with memoization)
# =====================================
def canBeSegmented_topdown(s, wordDict, memo=None):
    if memo is None:
        memo = {}  # Create memo dictionary on first call

    if s in memo:
        return memo[s]  # Return cached result

    if s == "":
        return True  # Base case: successfully segmented whole string

    for word in wordDict:
        if s.startswith(word):
            # Recursively check if the rest of the string can be segmented
            if canBeSegmented_topdown(s[len(word):], wordDict, memo):
                memo[s] = True  # Cache result before returning
                return True

    memo[s] = False  # No valid segmentation found
    return False


# =====================================
# BOTTOM-UP DYNAMIC PROGRAMMING
# (Iterative tabulation)
# =====================================
def canBeSegmented_bottomup(s, wordDict):
    dp = [False] * (len(s) + 1)
    dp[0] = True  # Base case: empty string can be segmented

    for i in range(1, len(s) + 1):
        for word in wordDict:
            if i >= len(word) and dp[i - len(word)]:
                # Check if the word ends at position i
                if s[i - len(word):i] == word:
                    dp[i] = True
                    break  # No need to check other words once one works

    return dp[len(s)]