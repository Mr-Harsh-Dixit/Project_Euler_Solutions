def solve() -> int:
    pow5 = [d**5 for d in range(10)]
    limit = 6 * (9**5)  # 354294

    total = 0
    for n in range(2, limit + 1):
        s = 0
        x = n
        while x > 0:
            s += pow5[x % 10]
            x //= 10
        if s == n:
            total += n

    return total

if __name__ == "__main__":
    print(solve())  # 443839
