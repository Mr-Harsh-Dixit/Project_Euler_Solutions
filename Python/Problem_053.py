def euler_53(limit: int = 1_000_000, N: int = 100) -> int:
    total = 0

    for n in range(1, N + 1):
        c = 1  # C(n,0)
        for r in range(1, n // 2 + 1):
            c = c * (n - r + 1) // r  # exact division
            if c > limit:
                total += (n - 2 * r + 1)
                break

    return total

if __name__ == "__main__":
    print(euler_53())  # 4075
