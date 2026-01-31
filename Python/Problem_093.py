from math import gcd
from itertools import combinations

class Frac:
    __slots__ = ("n", "d")
    def __init__(self, n: int, d: int = 1):
        if d == 0:
            raise ZeroDivisionError
        if d < 0:
            n, d = -n, -d
        g = gcd(abs(n), d)
        self.n = n // g
        self.d = d // g

    def __add__(self, other): return Frac(self.n * other.d + other.n * self.d, self.d * other.d)
    def __sub__(self, other): return Frac(self.n * other.d - other.n * self.d, self.d * other.d)
    def __mul__(self, other): return Frac(self.n * other.n, self.d * other.d)
    def __truediv__(self, other):
        if other.n == 0:
            raise ZeroDivisionError
        return Frac(self.n * other.d, self.d * other.n)

    def __hash__(self): return hash((self.n, self.d))
    def __eq__(self, other): return self.n == other.n and self.d == other.d

def all_values(nums):
    # nums: list[Frac]
    if len(nums) == 1:
        return {nums[0]}

    out = set()
    L = len(nums)
    for i in range(L):
        for j in range(i + 1, L):
            a, b = nums[i], nums[j]
            rest = [nums[k] for k in range(L) if k != i and k != j]

            # commutative ops once
            out |= all_values(rest + [a + b])
            out |= all_values(rest + [a * b])

            # non-commutative both orders
            out |= all_values(rest + [a - b])
            out |= all_values(rest + [b - a])

            if b.n != 0:
                out |= all_values(rest + [a / b])
            if a.n != 0:
                out |= all_values(rest + [b / a])

    return out

def euler_93():
    best_len = 0
    best = None

    for digits in combinations(range(1, 10), 4):
        fracs = [Frac(x) for x in digits]
        vals = all_values(fracs)

        ints = set()
        for v in vals:
            if v.d == 1 and v.n > 0:
                ints.add(v.n)

        n = 1
        while n in ints:
            n += 1
        run_len = n - 1

        if run_len > best_len:
            best_len = run_len
            best = digits

    return "".join(map(str, best))

if __name__ == "__main__":
    print(euler_93())  # 1258
