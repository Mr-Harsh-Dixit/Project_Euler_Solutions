from collections import deque

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

def is_truncatable(p: int, is_prime: bytearray) -> bool:
    if p < 10:
        return False

    # right truncations
    x = p
    while x > 0:
        if not is_prime[x]:
            return False
        x //= 10

    # left truncations
    s = str(p)
    for i in range(len(s)):
        if not is_prime[int(s[i:])]:
            return False

    return True

def solve() -> int:
    LIMIT = 1_000_000  # plenty for Euler 37
    is_prime = sieve(LIMIT)

    q = deque([2, 3, 5, 7])
    found = []

    while len(found) < 11:
        n = q.popleft()
        for d in (1, 3, 7, 9):
            m = n * 10 + d
            if m <= LIMIT and is_prime[m]:
                q.append(m)
                if is_truncatable(m, is_prime):
                    found.append(m)

    return sum(found)

if __name__ == "__main__":
    print(solve())  # 748317
