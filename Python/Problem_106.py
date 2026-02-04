from math import comb

def catalan(k: int) -> int:
    return comb(2*k, k) // (k + 1)

def needed_tests(n: int) -> int:
    total = 0
    for k in range(2, n//2 + 1):
        ways_pick = comb(n, 2*k)
        splits = comb(2*k, k)
        noncross = catalan(k)
        need = (splits - 2*noncross) // 2
        total += ways_pick * need
    return total

if __name__ == "__main__":
    print(needed_tests(12))  # 21384
