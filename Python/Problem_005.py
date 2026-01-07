def gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a


def lcm(a: int, b: int) -> int:
    return a // gcd(a, b) * b


def solve(n: int = 20) -> int:
    result = 1
    for i in range(2, n + 1):
        result = lcm(result, i)
    return result


if __name__ == "__main__":
    print(solve())  # 232792560
