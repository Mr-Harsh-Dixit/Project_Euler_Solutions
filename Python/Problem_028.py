def solve(N: int = 1001) -> int:
    total = 1
    for n in range(3, N + 1, 2):
        total += 4 * n * n - 6 * (n - 1)
    return total

if __name__ == "__main__":
    print(solve())  # 669171001
