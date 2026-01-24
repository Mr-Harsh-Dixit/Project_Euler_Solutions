from math import isqrt

def sieve(n: int) -> list[int]:
    is_p = bytearray(b"\x01") * (n + 1)
    is_p[0:2] = b"\x00\x00"
    for i in range(2, isqrt(n) + 1):
        if is_p[i]:
            step = i
            start = i * i
            is_p[start:n+1:step] = b"\x00" * (((n - start) // step) + 1)
    return [i for i in range(2, n + 1) if is_p[i]]

def mod_pow(a: int, e: int, mod: int) -> int:
    res = 1
    a %= mod
    while e:
        if e & 1:
            res = (res * a) % mod
        a = (a * a) % mod
        e >>= 1
    return res

def is_prime_mr(n: int) -> bool:
    if n < 2:
        return False
    small = (2,3,5,7,11,13,17,19,23,29,31,37)
    for p in small:
        if n == p:
            return True
        if n % p == 0:
            return False

    # write n-1 = d * 2^s
    d = n - 1
    s = 0
    while (d & 1) == 0:
        d >>= 1
        s += 1

    # Deterministic bases for 32-bit-ish range (works comfortably here)
    for a in (2, 3, 5, 7, 11):
        if a % n == 0:
            continue
        x = mod_pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(s - 1):
            x = (x * x) % n
            if x == n - 1:
                break
        else:
            return False
    return True

def digits10(x: int) -> int:
    # small fast digit count
    if x < 10: return 1
    if x < 100: return 2
    if x < 1000: return 3
    if x < 10000: return 4
    return 5

def euler_60(limit: int = 10000) -> int:
    primes = [p for p in sieve(limit) if p not in (2, 5)]
    pow10 = [1, 10, 100, 1000, 10000, 100000]  # up to 5 digits
    prime_cache: dict[int, bool] = {}

    def concat(a: int, b: int) -> int:
        return a * pow10[digits10(b)] + b

    def is_prime_cached(x: int) -> bool:
        v = prime_cache.get(x)
        if v is None:
            v = is_prime_mr(x)
            prime_cache[x] = v
        return v

    def compatible(a: int, b: int) -> bool:
        return is_prime_cached(concat(a, b)) and is_prime_cached(concat(b, a))

    # Build adjacency lists (only forward edges to keep sums small)
    adj = {p: [] for p in primes}
    for i, p in enumerate(primes):
        for q in primes[i+1:]:
            if compatible(p, q):
                adj[p].append(q)

    best_sum = 10**18
    best_set = None

    # Fast intersection of sorted lists
    def intersect(a: list[int], b: list[int]) -> list[int]:
        i = j = 0
        out = []
        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                out.append(a[i]); i += 1; j += 1
            elif a[i] < b[j]:
                i += 1
            else:
                j += 1
        return out

    def search(chosen: list[int], candidates: list[int], ssum: int):
        nonlocal best_sum, best_set
        k = len(chosen)
        if k == 5:
            if ssum < best_sum:
                best_sum = ssum
                best_set = chosen[:]
            return
        if not candidates:
            return
        if ssum >= best_sum:
            return

        need = 5 - k
        for idx, v in enumerate(candidates):
            # lower bound pruning (since candidates are increasing)
            if ssum + v * need >= best_sum:
                break
            new_cands = intersect(candidates[idx+1:], adj[v])
            search(chosen + [v], new_cands, ssum + v)

    for p in primes:
        # quick bound: smallest possible sum starting with p
        if p * 5 >= best_sum:
            break
        search([p], adj[p], p)

    # best_sum should be 26033
    return int(best_sum)

if __name__ == "__main__":
    print(euler_60())  # 26033
