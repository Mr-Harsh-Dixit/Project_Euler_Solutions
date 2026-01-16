def solve(limit: int = 28123) -> int:
    # proper divisor sums
    d = [0] * (limit + 1)
    for i in range(1, limit // 2 + 1):
        for j in range(2 * i, limit + 1, i):
            d[j] += i

    abundants = [n for n in range(12, limit + 1) if d[n] > n]

    can = bytearray(limit + 1)
    for i, a in enumerate(abundants):
        for b in abundants[i:]:
            s = a + b
            if s > limit:
                break
            can[s] = 1

    total = 0
    for n in range(1, limit + 1):
        if not can[n]:
            total += n
    return total

if __name__ == "__main__":
    print(solve())  # 4179871
