def solve(N: int = 100000, K: int = 10000) -> int:
    rad = [1] * (N + 1)

    for p in range(2, N + 1):
        if rad[p] == 1:  # prime
            for m in range(p, N + 1, p):
                rad[m] *= p

    pairs = [(rad[n], n) for n in range(1, N + 1)]
    pairs.sort()  # sorts by first then second automatically
    return pairs[K - 1][1]

if __name__ == "__main__":
    print(solve())  # 21417
