PRIMES = [2,3,5,7,11,13,17,19,23,29,31]
TARGET = 8_000_000

best = 10**40

def dfs(i, max_exp, n, prod):
    global best
    if prod > TARGET:
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
        dfs(i + 1, e, nn, prod * (2*e + 1))

def solve():
    global best
    dfs(0, 60, 1, 1)
    return best

if __name__ == "__main__":
    print(solve())  # 9350130049860600
