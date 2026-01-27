def euler_71(limit: int = 1_000_000) -> int:
    best_n, best_d = 0, 1

    for d in range(2, limit + 1):
        n = (3 * d - 1) // 7  # largest n/d < 3/7
        if n * best_d > best_n * d:
            best_n, best_d = n, d

    return best_n

if __name__ == "__main__":
    print(euler_71())  # 428570
