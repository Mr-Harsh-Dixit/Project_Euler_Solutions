import math

MOD = 1_000_000_000
TARGET_MASK = (1 << 10) - 2  # bits 1..9 set

def is_pandigital_1_to_9(x: int) -> bool:
    if x < 100_000_000:  # must be 9 digits
        return False
    mask = 0
    for _ in range(9):
        d = x % 10
        if d == 0:
            return False
        bit = 1 << d
        if mask & bit:
            return False
        mask |= bit
        x //= 10
    return mask == TARGET_MASK

# precompute constants
phi = (1.0 + 5.0 ** 0.5) / 2.0
logphi = math.log10(phi)
logsqrt5 = math.log10(5.0) / 2.0

def first9_digits_fib(n: int) -> int:
    x = n * logphi - logsqrt5
    frac = x - math.floor(x)
    return int(10 ** (frac + 8))

def solve() -> int:
    a, b = 1, 1  # F1, F2 (mod MOD)
    n = 2
    while True:
        n += 1
        a, b = b, (a + b) % MOD

        if is_pandigital_1_to_9(b):
            lead = first9_digits_fib(n)
            if is_pandigital_1_to_9(lead):
                return n

if __name__ == "__main__":
    print(solve())  # 329468
