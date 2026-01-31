def euler_94(limit: int = 1_000_000_000) -> int:
    def step(x: int, y: int) -> tuple[int, int]:
        return 7 * x + 24 * y, 2 * x + 7 * y

    total = 0

    # Family 1: (a, a, a+1), seed (x,y)=(14,4) where x = 3a - 1
    x, y = 14, 4
    while True:
        a = (x + 1) // 3
        p = 3 * a + 1
        if p > limit:
            break
        total += p
        x, y = step(x, y)

    # Family 2: (a, a, a-1), seed (x,y)=(52,15) where x = 3a + 1
    x, y = 52, 15
    while True:
        a = (x - 1) // 3
        p = 3 * a - 1
        if p > limit:
            break
        total += p
        x, y = step(x, y)

    return total

if __name__ == "__main__":
    print(euler_94())  # 518408346
