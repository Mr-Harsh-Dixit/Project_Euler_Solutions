def mod_pow(a: int, e: int, mod: int) -> int:
    res = 1
    a %= mod
    while e > 0:
        if e & 1:
            res = (res * a) % mod
        a = (a * a) % mod
        e >>= 1
    return res

def solve() -> str:
    MOD = 10_000_000_000
    total = 0
    for i in range(1, 1001):
        total = (total + mod_pow(i, i, MOD)) % MOD
    return f"{total:010d}"

if __name__ == "__main__":
    print(solve())  # 9110846700
