def is_pal(s: str) -> bool:
    return s == s[::-1]

def solve(limit: int = 1_000_000) -> int:
    total = 0
    for n in range(1, limit, 2):  # only odd
        if is_pal(str(n)) and is_pal(bin(n)[2:]):  # bin() has no leading zeros
            total += n
    return total

if __name__ == "__main__":
    print(solve())  # 872187
