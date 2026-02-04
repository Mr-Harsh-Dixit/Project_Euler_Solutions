import math

PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
TARGET = 2000

best = 10**30

def dfs(i: int, max_exp: int, n: int, divprod: int):
    global best
    if divprod > TARGET:
        best = min(best, n)
        return
    if i >= len(PRIMES) or n >= best:
        return

    p = PRIMES[i]
    val = 1
    for e in range(1, max_exp + 1):
        val *= p
        nn = n * val
        if nn >= best:
            break
        dfs(i + 1, e, nn, divprod * (2 * e + 1))

def solve():
    global best
    best = 10**30
    dfs(0, 60, 1, 1)
    return best

if __name__ == "__main__":
    print(solve())  # 180180
