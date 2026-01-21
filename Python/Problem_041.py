from itertools import permutations
from math import isqrt

def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    r = isqrt(n)
    f = 3
    while f <= r:
        if n % f == 0:
            return False
        f += 2
    return True

def solve() -> int:
    digits = "7654321"
    for p in permutations(digits):
        num = int("".join(p))
        if is_prime(num):
            return num
    return -1

if __name__ == "__main__":
    print(solve())  # 7652413
