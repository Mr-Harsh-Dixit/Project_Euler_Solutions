from math import gcd

def solve() -> int:
    num_prod = 1
    den_prod = 1

    for n in range(10, 100):
        for d in range(n + 1, 100):
            # trivial examples like 30/50
            if n % 10 == 0 and d % 10 == 0:
                continue

            ns = str(n)
            ds = str(d)

            for c in ns:
                if c == '0':
                    continue
                if c in ds:
                    # remove ONE occurrence
                    n2s = ns.replace(c, "", 1)
                    d2s = ds.replace(c, "", 1)
                    if not n2s or not d2s:
                        continue
                    n2 = int(n2s)
                    d2 = int(d2s)
                    if d2 != 0 and n * d2 == d * n2:
                        num_prod *= n
                        den_prod *= d

    g = gcd(num_prod, den_prod)
    return den_prod // g

if __name__ == "__main__":
    print(solve())  # 100
