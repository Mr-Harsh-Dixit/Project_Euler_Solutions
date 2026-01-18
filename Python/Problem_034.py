import math

def solve() -> int:
    fact = [math.factorial(d) for d in range(10)]
    limit = 7 * fact[9]  # 2540160

    total = 0
    for n in range(3, limit + 1):
        s = 0
        x = n
        while x > 0:
            s += fact[x % 10]
            x //= 10
        if s == n:
            total += n

    return total

if __name__ == "__main__":
    print(solve())  # 40730
