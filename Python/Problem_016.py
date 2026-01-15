def solve() -> int:
    n = 2 ** 1000
    return sum(int(ch) for ch in str(n))

if __name__ == "__main__":
    print(solve())  # 1366
