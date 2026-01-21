from math import isqrt

def pent(n: int) -> int:
    return n * (3 * n - 1) // 2

def is_pent(x: int) -> bool:
    disc = 1 + 24 * x
    s = isqrt(disc)
    return s * s == disc and (1 + s) % 6 == 0

def solve() -> int:
    best = 10**30

    k = 2
    while True:
        pk = pent(k)
        # walk j downward so D increases; break when D >= best
        for j in range(k - 1, 0, -1):
            pj = pent(j)
            d = pk - pj
            if d >= best:
                break
            if is_pent(d) and is_pent(pk + pj):
                best = d

        # stop when the smallest possible new diff already exceeds best
        if best < 10**30 and (pent(k) - pent(k - 1)) > best:
            break

        k += 1

    return best

if __name__ == "__main__":
    print(solve())  # 5482660
