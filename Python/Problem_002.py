def solve(limit: int = 4_000_000) -> int:
    total = 0
    a, b = 2, 8  # even Fibonacci terms

    while a <= limit:
        total += a
        a, b = b, 4 * b + a

    return total

if __name__ == "__main__":
    print(solve())  # 4613732
