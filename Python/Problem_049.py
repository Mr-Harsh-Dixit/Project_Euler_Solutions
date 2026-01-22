def sieve(limit: int) -> bytearray:
    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[0:2] = b"\x00\x00"
    p = 2
    while p * p <= limit:
        if is_prime[p]:
            start = p * p
            is_prime[start::p] = b"\x00" * (((limit - start) // p) + 1)
        p += 1
    return is_prime

def signature(n: int) -> str:
    return "".join(sorted(str(n)))

def solve() -> str:
    is_prime = sieve(9999)

    groups = {}
    for p in range(1000, 10000):
        if is_prime[p]:
            sig = signature(p)
            groups.setdefault(sig, []).append(p)

    for sig, arr in groups.items():
        if len(arr) < 3:
            continue
        arr.sort()
        s = set(arr)
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                a, b = arr[i], arr[j]
                c = 2 * b - a
                if c in s:
                    if a == 1487 and b == 4817:
                        continue
                    return f"{a}{b}{c}"
    return ""

if __name__ == "__main__":
    print(solve())  # 296962999629
