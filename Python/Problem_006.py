def solve(n: int = 100) -> int:
    s = n * (n + 1) // 2
    sq = n * (n + 1) * (2 * n + 1) // 6
    return s * s - sq


if __name__ == "__main__":
    print(solve())  # 25164150
