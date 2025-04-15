# Question 9. [10 marks]
# You are given a staircase with n steps, and you can climb either 1, 2, or 3 steps at a time. Each step has
# an associated cost, represented by a list cost of length n, where cost[i] is the cost of stepping on step i.
# The goal is to find the minimum cost to reach the top of the staircase, starting from the bottom step (0).
# You can start by taking either 1, 2, or 3 steps. Write a function in Python which takes in the list cost,
# and returns a list that corresponds to the least-cost plan. The list could be for example
# 2, 1, 3
# , which would correspond to “first take two steps, then one step, then three steps.”

'''
1-wide stride
2-wide stride
3-wide stride

each staircase step i has an associated cost, cost[i]
n steps, theres a list of costs and the list is n elems long
min cost to reach top of staircase starting from bottom step (step 0)

take in list cost
return list corresponding to least cost plan -> path of steps to take
'''

# • Intuition: (I will be using bottom up)
# • To get to some step i, the cost will be either:
# cost[i - 1] + cost[1]
# cost[i - 2] + cost[2]
# cost[i - 3] + cost[3]
# • Think about it as if we are approaching step i. We can approach it from 1, 2, or 3 steps away
# • Do you see the relationship we can use?
# • Once minimum cost for step i is found, back-track to find path (how many 
# steps taken each time

def newsteps(costlist):
    dp = [0] * len(costlist)
    steps = [0] * len(costlist) # to keep track of all the steps so far

    # start at the first stair
    dp[0] = costlist[0]

    # to get to the second stair
    dp[1] = dp[0] + costlist[1]
    # there is only one way to get to second stair, which is to take 1 step from the bottom stair
    steps[1] = 1

    # to get to the third stair
    dp[2] = min(dp[1] + costlist[2], dp[0] + costlist[2])
    # start at stair 1 and take 1 step to get to stair 2
    # start at stair 0 and take 2 steps to get to stair 2, skipping stair 1

    # calculate steps for each
    if (dp[2] == (dp[1] + costlist[2])):
        steps[2] = 1
    else:
        steps[2] = 2
    
    # now calculate the rest based on these base cases
    for i in range(3, len(costlist)): # start at 3rd stair cuz we've calculated for 0th, 1st, and 2nd stairs already
        dp[i] = costlist[i] + min(dp[i-1], dp[i-2], dp[i-3])
        if (dp[i] - costlist[i] == dp[i - 1]):
            steps[i] = 1
        elif (dp[i] - costlist[i] == dp[i-2]):
            steps[i] = 2
        else:
            steps[i] = 3

    leastcostplan = []

    i = len(costlist) - 1
    while i >= 0:
        leastcostplan.insert(0, steps[i]) # how does this keep track of the actual path? isnt it just step
        #we know we took 'steps[i]' steps to get to step i, 
        # so go back that many steps and repeat!
        i -= steps[i]
    
    return leastcostplan

def stepsanswer(costlist):
    dp = [0] * (len(costlist))
    pathofstepstotake = [0] * (len(costlist))

    if len(costlist) == 0:
        return None
    if len(costlist) > 1:
        dp[1] = dp[0] + costlist[1]
        pathofstepstotake[1] = 1
    if len(costlist) > 2:
        dp[2] = costlist[1]
    if len(costlist) > 3:
        dp[3] = costlist[2]

    min = float('inf')
    
    for n in costlist:
        for i in range(3):
            val = (dp[n - i]) + dp[i]
            if val < min:
                min = val
                pathofstepstotake[n] = i

    return pathofstepstotake



def stepswithmorehint(costlist):
    dp = [0] * (len(costlist) + 1)
    if len(costlist) == 0:
        return None
    if len(costlist) > 1:
        dp[0] = costlist[0]
    if len(costlist) > 2:
        dp[1] = costlist[1]
    if len(costlist) > 3:
        dp[2] = costlist[2]

    min = float('inf')
    pathofstepstotake = []
    
    for n in costlist:
        for i in range(3):
            val = (dp[n - i]) + dp[i]
            if val < min:
                min = val
                pathofstepstotake.append(i)

    return pathofstepstotake



    #     dp[n - 1]
    #     dp[n] = min(dp[n - 1] + dp[1], dp[n - 2] + dp[2], dp[n - 3] + dp[3])

    # return pathofstepstotake

def stepswithhint(costlist):
    dp = [None] * (len(costlist) + 1)
    if len(costlist) == 0:
        return None
    # dp[0] = costlist[0]
    for n in range(0, len(costlist)):
        dp[n] = costlist[n] + min(stepswithhint(costlist))
        opt1
        opt2
        opt3
        dp[n] = min(costlist[n] + stepswithhint(costlist)
    dp[1] = costlist
        opt1 = costlist[1] + stepswithhint(costlist)
        opt2 = costlist[2] + 
        opt3 = costlist[3] + 
    return min(opt1, opt2, opt3) + costlist[0]

def steps(costlist):
    steppath = []
    dp = [None] * len(costlist)
    dp[0] = costlist[0]
    for n in range(1, len(costlist)):
        dp[n] = min(steps(costlist[n]), steps(costlist[1:]), steps(costlist[2:]))
    return steppath

def steps(costlist, memo = {}):
    if 
    for n in range(len(costlist)):
        opt1 = steps(sublist(costlist, 1 to end))
        opt2 = steps(sublist(costlist, 2 to end))
        opt3 = steps(sublist(costlist, 3 to end))
    return costlist[n] + min(opt1, opt2, opt3)

def steps(costlist):
    for n in range(len(costlist)):
        opt1 = steps(sublist(costlist, 1 to end))
        opt2 = steps(sublist(costlist, 2 to end))
        opt3 = steps(sublist(costlist, 3 to end))
    return costlist[n] + min(opt1, opt2, opt3)