import math

def non_bouncy_below_10_pow_n(n: int) -> int:
    # NB(n) = C(n+9,9) + C(n+10,10) - 10n - 2
    return math.comb(n + 9, 9) + math.comb(n + 10, 10) - 10 * n - 2

if __name__ == "__main__":
    print(non_bouncy_below_10_pow_n(100))  # 51161058134250
