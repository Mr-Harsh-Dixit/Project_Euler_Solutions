import math

def is_square(n: int) -> bool:
    r = math.isqrt(n)
    return r * r == n

def euler_86(target: int = 1_000_000) -> int:
    total = 0
    M = 0

    while total <= target:
        M += 1
        z = M
        zz = z * z
        for s in range(2, 2 * z + 1):
            if is_square(s * s + zz):
                lo = max(1, s - z)
                hi = min(z, s // 2)
                if hi >= lo:
                    total += hi - lo + 1

    return M

if __name__ == "__main__":
    print(euler_86())  # 1818
