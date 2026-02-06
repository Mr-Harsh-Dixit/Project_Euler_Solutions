def digit_sum(n: int) -> int:
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

def solve() -> int:
    LIMIT = 10**18
    vals = set()

    for s in range(2, 500):
        v = s * s
        while v <= LIMIT:
            if v >= 10 and digit_sum(v) == s:
                vals.add(v)
            v *= s

    arr = sorted(vals)
    return arr[29]  # a30

if __name__ == "__main__":
    print(solve())  # 248155780267521
