from math import isqrt

def is_pent(x: int) -> bool:
    disc = 1 + 24 * x
    s = isqrt(disc)
    return s * s == disc and (1 + s) % 6 == 0

def solve() -> int:
    n = 144  # after H_143 = 40755
    while True:
        h = n * (2 * n - 1)
        if is_pent(h):
            return h
        n += 1

if __name__ == "__main__":
    print(solve())  # 1533776805
