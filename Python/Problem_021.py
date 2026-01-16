def solve(N: int = 10_000) -> int:
    d = [0] * N

    for i in range(1, N // 2 + 1):
        for j in range(2 * i, N, i):
            d[j] += i

    total = 0
    for a in range(2, N):
        b = d[a]
        if b != a and b < N and d[b] == a:
            total += a

    return total

if __name__ == "__main__":
    print(solve())  # 31626
