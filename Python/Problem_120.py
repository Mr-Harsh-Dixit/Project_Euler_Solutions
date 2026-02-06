def solve(limit: int = 1000) -> int:
    total = 0
    for a in range(3, limit + 1):
        if a % 2 == 1:
            total += a * a - a
        else:
            total += a * a - 2 * a
    return total

if __name__ == "__main__":
    print(solve(1000))  # 333082500

