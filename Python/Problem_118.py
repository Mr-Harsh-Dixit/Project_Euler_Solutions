from functools import lru_cache

ALL = (1 << 9) - 1  # digits 1..9

def is_prime(n: int) -> bool:
    if n < 2:
        return False
    small = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37)
    for p in small:
        if n % p == 0:
            return n == p

    # Miller-Rabin for 32-bit range is overkill but fast in Python
    d = n - 1
    s = 0
    while d % 2 == 0:
        s += 1
        d //= 2

    def check(a: int) -> bool:
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            return True
        for _ in range(s - 1):
            x = (x * x) % n
            if x == n - 1:
                return True
        return False

    for a in (2, 3, 5, 7, 11):
        if a % n == 0:
            continue
        if not check(a):
            return False
    return True

def digits_from_mask(mask: int):
    # bit0 -> digit 1, bit8 -> digit 9
    return [i + 1 for i in range(9) if (mask >> i) & 1]

def primes_for_mask(mask: int):
    digs = digits_from_mask(mask)
    # digit-sum mod 3 pruning (only single-digit 3 survives)
    s = sum(digs)
    if s % 3 == 0 and not (len(digs) == 1 and digs[0] == 3):
        return []

    res = set()
    used = [False] * len(digs)
    digs.sort()

    def backtrack(cur: int, depth: int):
        if depth == len(digs):
            # quick last digit filter
            if len(digs) > 1:
                last = cur % 10
                if last % 2 == 0 or last == 5:
                    return
            if is_prime(cur):
                res.add(cur)
            return

        for i in range(len(digs)):
            if used[i]:
                continue
            # avoid duplicate permutations when digits repeat (they don't here, but keep it clean)
            used[i] = True
            backtrack(cur * 10 + digs[i], depth + 1)
            used[i] = False

    backtrack(0, 0)
    return sorted(res)

# precompute prime lists per mask
PRIMES = [[] for _ in range(ALL + 1)]
for m in range(1, ALL + 1):
    PRIMES[m] = primes_for_mask(m)

@lru_cache(maxsize=None)
def dfs(remaining_mask: int, last_val: int) -> int:
    if remaining_mask == 0:
        return 1

    total = 0
    sub = remaining_mask
    while sub:
        plist = PRIMES[sub]
        if plist:
            # iterate only values > last_val (plist sorted)
            # manual bisect to avoid import, because why not
            lo, hi = 0, len(plist)
            while lo < hi:
                mid = (lo + hi) // 2
                if plist[mid] <= last_val:
                    lo = mid + 1
                else:
                    hi = mid
            for v in plist[lo:]:
                total += dfs(remaining_mask ^ sub, v)
        sub = (sub - 1) & remaining_mask

    return total

def solve():
    return dfs(ALL, 0)

if __name__ == "__main__":
    print(solve())  # 44680
