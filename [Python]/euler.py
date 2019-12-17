import math

# binomial coefficient
# Pascal's triangle
# n! / (k! (n-k)!)
binomCache = dict()
def choose(n, k):
    if n<0 or k<0 or k>n:
        return 0
    if n==0 or k==0:
        return 1
    if (n,k) in binomCache:
        return binomCache[(n,k)]
    answer = choose(n-1, k) + choose(n-1, k-1)
    binomCache[(n,k)] = answer
    return answer