import math

def minimal_x_for_D(D: int) -> int:
    a0 = int(math.isqrt(D))
    if a0 * a0 == D:
        return 0

    m, d, a = 0, 1, a0

    p_m2, p_m1 = 0, 1
    q_m2, q_m1 = 1, 0

    while True:
        p = a * p_m1 + p_m2
        q = a * q_m1 + q_m2

        if p * p - D * q * q == 1:
            return p

        p_m2, p_m1 = p_m1, p
        q_m2, q_m1 = q_m1, q

        m = d * a - m
        d = (D - m * m) // d
        a = (a0 + m) // d

def euler_66(limit: int = 1000) -> int:
    bestD = 0
    bestX = 0

    for D in range(2, limit + 1):
        a0 = int(math.isqrt(D))
        if a0 * a0 == D:
            continue
        x = minimal_x_for_D(D)
        if x > bestX:
            bestX = x
            bestD = D

    return bestD

if __name__ == "__main__":
    print(euler_66())  # 661
