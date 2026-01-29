import math

def euler_85(target: int = 2_000_000) -> int:
    best_diff = 10**18
    best_area = 0

    for m in range(1, 2001):
        tm = m * (m + 1) // 2
        x = target / tm  # float is fine here (only for estimating n)

        n0 = int((math.isqrt(int(1 + 8 * x)) - 1) // 2)  # rough
        # safer: do pure float for n0 then int
        n0 = int((math.sqrt(1.0 + 8.0 * x) - 1.0) / 2.0)

        for n in (n0, n0 + 1):
            if n <= 0:
                continue
            tn = n * (n + 1) // 2
            rect = tm * tn
            diff = abs(rect - target)
            if diff < best_diff:
                best_diff = diff
                best_area = m * n

    return best_area

if __name__ == "__main__":
    print(euler_85())  # 2772
