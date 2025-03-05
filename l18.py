def fib(n, mem={}):
    if n in mem:
        return mem[n]
    if n <= 1:
        return n
    mem[n]= fib(n-1, mem)+ fib(n-2, mem)
    return mem[n]
# how many calls to fib are there if we start with fib(n)?
# n levels, one call to the right from every level
# 2n-1 calls (the -1 is because no call to the left from fib(1))
# Complexity: O(n) since each call takes same amount of time (approx)

def fib_iter(n):
    fib_list = [0] * (n+1)
    fib_list[0:2] = [0, 1]
    for i in range(2, n+1):
        fib_list[i] = fib_list[i-1] + fib_list[i-2]
    return fib_list[n]
# O(n) because we have to compute ~n entities in a list using a for loop
# subproblems:
# - compute fib_list[i] for i = 0, 1, 2, 3, ...k, ..., n


# painting houses
# no two adjacent can be the same colour
# minimize the entire cost
# subproblems:
# - R(i) = minimal cost to paint first i houses with ith house painted red
# R(i) = cost(i, red)+ min(G(i - 1), B(i - 1))
# - B(i) = minimal cost to paint first i houses with ith house painted blue
# B(i) = cost(i, blue)+ min(G(i - 1), R(i - 1))
# - G(i) = minimal cost to paint first i houses with ith house painted green
# G(i) = cost(i, green)+ min(R(i - 1), B(i - 1))
# cost(i) = min(R(i), G(i), B(i))