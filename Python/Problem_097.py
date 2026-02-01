def euler_97():
    MOD = 10**10

    def mod_pow(base, exp):
        res = 1
        base %= MOD
        while exp > 0:
            if exp & 1:
                res = (res * base) % MOD
            base = (base * base) % MOD
            exp >>= 1
        return res

    p = mod_pow(2, 7830457)
    ans = (28433 * p + 1) % MOD
    print(f"{ans:010d}")  # 8739992577

if __name__ == "__main__":
    euler_97()
