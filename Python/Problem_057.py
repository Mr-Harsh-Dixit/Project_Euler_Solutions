def add_digits(a: list[int], b: list[int]) -> list[int]:
    n = max(len(a), len(b))
    out = []
    carry = 0
    for i in range(n):
        da = a[i] if i < len(a) else 0
        db = b[i] if i < len(b) else 0
        s = da + db + carry
        out.append(s % 10)
        carry = s // 10
    while carry:
        out.append(carry % 10)
        carry //= 10
    return out

def add_scaled_digits(a: list[int], b: list[int], k: int) -> list[int]:
    n = max(len(a), len(b))
    out = []
    carry = 0
    for i in range(n):
        da = a[i] if i < len(a) else 0
        db = b[i] if i < len(b) else 0
        s = da + k * db + carry
        out.append(s % 10)
        carry = s // 10
    while carry:
        out.append(carry % 10)
        carry //= 10
    return out

def euler_57() -> int:
    p = [3]  # 3
    q = [2]  # 2
    count = 0

    for _ in range(1000):
        if len(p) > len(q):
            count += 1
        new_p = add_scaled_digits(p, q, 2)  # p + 2q
        new_q = add_digits(p, q)            # p + q
        p, q = new_p, new_q

    return count

if __name__ == "__main__":
    print(euler_57())  # 153
