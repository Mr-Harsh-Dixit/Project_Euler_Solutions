import math

def solve(limit: int = 2_000_000) -> int:
    if limit <= 2:
        return 0

    # Only odds: index i => number = 2*i + 3
    size = (limit - 1) // 2
    is_prime = bytearray(b"\x01") * size

    root = int(math.isqrt(limit - 1))
    max_i = (root - 3) // 2  # largest i where (2*i+3)^2 <= limit-1

    for i in range(max_i + 1):
        if is_prime[i]:
            p = 2 * i + 3
            start = (p * p - 3) // 2
            is_prime[start::p] = b"\x00" * (((size - 1 - start) // p) + 1)

    total = 2  # include prime 2
    for i, flag in enumerate(is_prime):
        if flag:
            total += 2 * i + 3

    return total

if __name__ == "__main__":
    print(solve())  # 142913828922
