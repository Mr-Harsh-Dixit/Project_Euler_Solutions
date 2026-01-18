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

def rotations(n: int) -> list[int]:
    s = str(n)
    return [int(s[i:] + s[:i]) for i in range(len(s))]

def solve(limit: int = 1_000_000) -> int:
    is_prime = sieve(limit)
    processed = bytearray(limit)

    bad_digits = set("024568")
    total = 0

    for p in range(2, limit):
        if not is_prime[p] or processed[p]:
            continue

        rots = rotations(p)
        for r in rots:
            if r < limit:
                processed[r] = 1

        s = str(p)
        if len(s) > 1 and any(ch in bad_digits for ch in s):
            continue

        if all(r < limit and is_prime[r] for r in rots):
            total += len(set(rots))  # count distinct rotations

    return total

if __name__ == "__main__":
    print(solve())  # 55
