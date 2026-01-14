def count_divisors(x: int) -> int:
    total = 1

    exp = 0
    while x % 2 == 0:
        x //= 2
        exp += 1
    if exp:
        total *= (exp + 1)

    p = 3
    while p * p <= x:
        exp = 0
        while x % p == 0:
            x //= p
            exp += 1
        if exp:
            total *= (exp + 1)
        p += 2

    if x > 1:
        total *= 2

    return total


def solve(threshold: int = 500) -> int:
    n = 1
    while True:
        if n % 2 == 0:
            a, b = n // 2, n + 1
        else:
            a, b = n, (n + 1) // 2

        if count_divisors(a) * count_divisors(b) > threshold:
            return n * (n + 1) // 2

        n += 1


if __name__ == "__main__":
    print(solve(500))  # 76576500
